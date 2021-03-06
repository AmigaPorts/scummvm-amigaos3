/*
README(.md) to .guide converter $VER: RM2AG.rexx 0.20 (18.05.2019)
This script converts a given markdown README file of ScummVM to a basic
hypertext Amiga guide file.
*/

PARSE ARG readme_md

/*
Check if the given file is really the readme.
If a given filename has spaces, AmigaDOS/AmigaCLI will add extra
quotation marks to secure a sane working path. We get rid of them to make
AREXX find the file.
*/
readme_md=COMPRESS(readme_md,'"')
OPEN(check_readme,readme_md,'R')
IF READCH(check_readme,18) = '# [ScummVM README]' THEN
	CLOSE(check_readme)
ELSE DO
	SAY "Not the ScummVM README.md file. Aborting!"
	CLOSE(check_readme)
	EXIT 0
END

OPEN(readme_read,readme_md,'R')
OPEN(guide_write,'README.guide','W')

/*
Prepare the Amiga guide file, add the intro and fixed text.
*/
WRITELN(guide_write,'@DATABASE ScummVM README.guide')
WRITELN(guide_write,'@$VER: ScummVM Readme 2.1.0git')
WRITELN(guide_write,'@(C) by The ScummVM team')
WRITELN(guide_write,'@AUTHOR The ScummVM team')
WRITELN(guide_write,'@WORDWRAP')
WRITELN(guide_write,'@NODE "main" "ScummVM README Guide"')
WRITELN(guide_write,'@{b}')
WRITELN(guide_write,SUBSTR(READLN(readme_read),4,14))
WRITELN(guide_write,'@{ub}')

/*
Creating the main (TOC) link nodes.
*/

DO WHILE EOF(readme_read) = 0
	working_line=READLN(readme_read)

	/*
	Check for the start of actual the content and, if found, leave the
	TOC link loop.
	*/
	IF POS('## <>1.0<>)',working_line) = 1 THEN
		LEAVE

	/*
	Check for any "rolled over" lines, if found, read in the rest (on the
	following line) and rejoin them again, before processing any further.
	e.g.	- [<>3.6.3<>) Broken Sword games
		cutscenes](#363-broken-sword-games-cutscenes)
	*/
	IF POS('- [<>',working_line) > 0 THEN DO
		IF POS('(#',working_line) = 0 THEN DO
			rejoin_line=COMPRESS(READLN(readme_read),' ')
			working_line=working_line rejoin_line
		END
	END

	/*
	If no chapter has been found, simply write the line and skip the rest.
	*/
	IF POS('- [',working_line) = 0 THEN
		WRITELN(guide_write,working_line)
	ELSE DO
		/*
		Fix the empty chapters:
		Two chapters (1.0 and 7.8) are "empty", consisting of only it's
		chapter names. We link them to their respective sub chapters
		(1.1 and 7.8.1), so we don't end up displaying a blank page.
		
		 If chapter 1.0 is found, add a link node to chapter 1.1.
		*/
		IF POS('  - [<>1.0<>)',working_line) = 1 THEN DO
			/*
			Get rid of the markers, so the following loops won't process
			them again.
			*/
			working_line=COMPRESS(working_line,'-[<>')
			WRITELN(guide_write,'  @{" 1.0 " Link "1.1"} 'SUBSTR(working_line,1,LASTPOS(']',working_line)-1))
		END

		/*
		If chapter 7.8 is found, add a link node to 7.8.1.
		*/
		IF POS('      - [<>7.8<>)',working_line) = 1 THEN DO
			/*
			Get rid of the markers, so the following loops won't process
			them again.
			*/
			working_line=COMPRESS(working_line,'-[<>')
			WRITELN(guide_write,'    @{" 7.8 " Link "7.8.1"} 'SUBSTR(working_line,1,LASTPOS(']',working_line)-1))
		END

		/*
		If a single number main chapter is found (1.0 upto 9.0), prepare
		and write the link node.
		Just for the record:
		A "\" (backslash) is treated as escape character in AmigaGuides.
		Thus we remove it from the node links.
		*/
		IF POS('- [<>',working_line) = 3 THEN DO
			WRITELN(guide_write,' ')
			WRITELN(guide_write,'  @{" 'SUBSTR(working_line,POS('<>',working_line)+2,LASTPOS('<>',working_line)-POS('<>',working_line)-2) '" Link "'SUBSTR(working_line,POS('<>',working_line)+2,LASTPOS('<>',working_line)-POS('<>',working_line)-2)'"} 'COMPRESS(SUBSTR(working_line,1,LASTPOS(']',working_line)-1),'*<>[]\'))
			/*
			Get rid of the markers, so the following loops won't process
			them again.
			*/
			working_line=COMPRESS(working_line,'-[<>')
		END

		/*
		If a single number level one sub chapter is found
		(i.e. 1.1, 1.2 etc.), prepare and write the link node.
		*/
		IF POS('- [<>',working_line) = 7 THEN DO
			WRITELN(guide_write,'    @{" 'SUBSTR(working_line,POS('<>',working_line)+2,LASTPOS('<>',working_line)-POS('<>',working_line)-2) '" Link "'SUBSTR(working_line,POS('<>',working_line)+2,LASTPOS('<>',working_line)-POS('<>',working_line)-2)'"} 'COMPRESS(SUBSTR(working_line,1,LASTPOS(']',working_line)-1),'*<>[]\'))
			/*
			Get rid of the markers, so the following loops won't process
			them again.
			*/
			working_line=COMPRESS(working_line,'.[<>')
		END

		/*
		If a level two sub chapter is found (i.e. 3.6.1, 3.6.2 etc.),
		prepare and write the link node.
		*/
		IF POS('- [<>',working_line) = 11 THEN DO
			WRITELN(guide_write,'      @{" 'SUBSTR(working_line,POS('<>',working_line)+2,LASTPOS('<>',working_line)-POS('<>',working_line)-2) '" Link "'SUBSTR(working_line,POS('<>',working_line)+2,LASTPOS('<>',working_line)-POS('<>',working_line)-2)'"} 'COMPRESS(SUBSTR(working_line,1,LASTPOS(']',working_line)-1),'*<>[]\'))
			/*
			Get rid of the markers, so the following loops won't process
			them again.
			*/
			working_line=COMPRESS(working_line,'.[<>')
		END
	END
END

/*
Finish the TOC (Hardcoded due the outro text would be read in last, but
needs to be written after the TOC creation).
*/
WRITELN(guide_write,'-----')
WRITELN(guide_write,' ')
WRITELN(guide_write,'Good Luck and Happy Adventuring!')
WRITELN(guide_write,'The ScummVM team.')
WRITELN(guide_write,'@{"https://www.scummvm.org/" System "URLOpen https://www.scummvm.org/"}')

/*
Creating the sub link nodes.
*/
DO WHILE EOF(readme_read) = 0
	/*
	Change the html/markdown links to AmigaGuide ones
	*/
	IF POS('[here](',working_line) > 0 THEN DO
		working_line=INSERT('@{"',working_line,POS('[',working_line)-1)
		working_line=INSERT('" link ',working_line,POS(']',working_line))
		working_line=INSERT('/main}',working_line,POS(')',working_line))
		working_line=COMPRESS(working_line,'()')
	END

	/*
	If no chapter has been found, simply write the line and skip the rest.
	*/
	IF POS('<>',working_line) = 0 THEN
		WRITELN(guide_write,working_line)
	ELSE DO
		/*
		Fix empty chapters:
		Two chapters (1.0 and 7.8) are "empty", consisting of only it's
		chapter names. We link them to their respective sub chapters
		(1.1 and 7.8.1), so we don't end up displaying a blank page.
		If chapter 1.1 is found don't close the NODE, just write the line.
		*/
		IF POS('<>1.1<>',working_line) = 1 THEN DO
			/*
			Get rid of the markers, so the following loops won't process
			them again.
			*/
			WRITELN(guide_write,COMPRESS(working_line,'<>'))
		END

		/*
		If chapter 7.8.1 is found don't close the NODE, just write the
		line.
		*/
		IF POS('<>7.8.1<>',working_line) = 1 THEN DO
			/*
			Get rid of the markers, so the following loops won't process
			them again.
			*/
			WRITELN(guide_write,COMPRESS(working_line,'<>'))
		END

		IF POS('<>',working_line) > 0 THEN DO
			/*
			Check for link references inside the text and create link
			nodes for them.
			*/
			IF POS('section <>',working_line) > 0 THEN DO
				working_line=SUBSTR(working_line,1,POS('<>',working_line)-1)'@{"'SUBSTR(working_line,POS('<>',working_line)+2,LASTPOS('<>',working_line)-POS('<>',working_line)-2)'" Link "'SUBSTR(working_line,POS('<>',working_line)+2,LASTPOS('<>',working_line)-POS('<>',working_line)-2)'"}'SUBSTR(working_line,LASTPOS('<>',working_line)+2)
				/*
				Get rid of the markers, so the following loops won't
				process them again.
				*/
				WRITELN(guide_write,COMPRESS(working_line,'<>'))
			END
			ELSE DO
				/*
				If a chapter has been found, prepare and write the link.
				*/
				WRITELN(guide_write,'@ENDNODE')
				WRITELN(guide_write,'@NODE "'SUBSTR(working_line,POS('<>',working_line)+2,LASTPOS('<>',working_line)-POS('<>',working_line)-2)'" "'COMPRESS(working_line,'<>#')'"')
				WRITELN(guide_write,' ')
				/*
				Get rid of the markers, so the following loops won't process
				them again.
				*/
				WRITELN(guide_write,COMPRESS(working_line,'<>'))
			END
		END
	END
	/*
	Read in the line at the end of the second loop, as the first line to
	work with was already read in on the end of the first loop.
	*/
	working_line=READLN(readme_read)

	/*
	If the outtro text is found, leave the loop and prepare for closing.
	*/
	IF POS('-----',working_line,1) =1 THEN
		LEAVE
END

WRITELN(guide_write,'@ENDNODE')

/*
Close the guide and clean up.
*/
WRITELN(guide_write,'@ENDNODE')

CLOSE(readme_read)
CLOSE(guide_write)

EXIT 0
