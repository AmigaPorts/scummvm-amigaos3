/* Copyright (C) 1994-2003 Revolution Software Ltd
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * $Header$
 */

#include "common/stdafx.h"
#include "common/util.h"
#include "sword2/sword2.h"
#include "sword2/interpreter.h"

namespace Sword2 {

// This file serves two purposes. It is compiled as part of the test functions
// of Linc, and also as part of the game

// I assume Linc was the name of some sort of development tool. Anyway, I've
// removed the pieces of code that were labelled as INSIDE_LINC, because we
// don't have it, and probably wouldn't have much use for it if we did.

// The machine code table

#define MAX_FN_NUMBER	117

#define OPCODE(x)	{ &Logic::x, #x }

void Logic::setupOpcodes(void) {
	static const OpcodeEntry opcodes[MAX_FN_NUMBER + 1] = {
		/* 00 */
		OPCODE(fnTestFunction),
		OPCODE(fnTestFlags),
		OPCODE(fnRegisterStartPoint),
		OPCODE(fnInitBackground),
		/* 04 */
		OPCODE(fnSetSession),
		OPCODE(fnBackSprite),
		OPCODE(fnSortSprite),
		OPCODE(fnForeSprite),
		/* 08 */
		OPCODE(fnRegisterMouse),
		OPCODE(fnAnim),
		OPCODE(fnRandom),
		OPCODE(fnPreLoad),
		/* 0C */
		OPCODE(fnAddSubject),
		OPCODE(fnInteract),
		OPCODE(fnChoose),
		OPCODE(fnWalk),
		/* 10 */
		OPCODE(fnWalkToAnim),
		OPCODE(fnTurn),
		OPCODE(fnStandAt),
		OPCODE(fnStand),
		/* 14 */
		OPCODE(fnStandAfterAnim),
		OPCODE(fnPause),
		OPCODE(fnMegaTableAnim),
		OPCODE(fnAddMenuObject),
		/* 18 */
		OPCODE(fnStartConversation),
		OPCODE(fnEndConversation),
		OPCODE(fnSetFrame),
		OPCODE(fnRandomPause),
		/* 1C */
		OPCODE(fnRegisterFrame),
		OPCODE(fnNoSprite),
		OPCODE(fnSendSync),
		OPCODE(fnUpdatePlayerStats),
		/* 20 */
		OPCODE(fnPassGraph),
		OPCODE(fnInitFloorMouse),
		OPCODE(fnPassMega),
		OPCODE(fnFaceXY),
		/* 24 */
		OPCODE(fnEndSession),
		OPCODE(fnNoHuman),
		OPCODE(fnAddHuman),
		OPCODE(fnWeWait),
		/* 28 */
		OPCODE(fnTheyDoWeWait),
		OPCODE(fnTheyDo),
		OPCODE(fnWalkToTalkToMega),
		OPCODE(fnFadeDown),
		/* 2C */
		OPCODE(fnISpeak),
		OPCODE(fnTotalRestart),
		OPCODE(fnSetWalkGrid),
		OPCODE(fnSpeechProcess),
		/* 30 */
		OPCODE(fnSetScaling),
		OPCODE(fnStartEvent),
		OPCODE(fnCheckEventWaiting),
		OPCODE(fnRequestSpeech),
		/* 34 */
		OPCODE(fnGosub),
		OPCODE(fnTimedWait),
		OPCODE(fnPlayFx),
		OPCODE(fnStopFx),
		/* 38 */
		OPCODE(fnPlayMusic),
		OPCODE(fnStopMusic),
		OPCODE(fnSetValue),
		OPCODE(fnNewScript),
		/* 3C */
		OPCODE(fnGetSync),
		OPCODE(fnWaitSync),
		OPCODE(fnRegisterWalkGrid),
		OPCODE(fnReverseMegaTableAnim),
		/* 40 */
		OPCODE(fnReverseAnim),
		OPCODE(fnAddToKillList),
		OPCODE(fnSetStandbyCoords),
		OPCODE(fnBackPar0Sprite),
		/* 44 */
		OPCODE(fnBackPar1Sprite),
		OPCODE(fnForePar0Sprite),
		OPCODE(fnForePar1Sprite),
		OPCODE(fnSetPlayerActionEvent),
		/* 48 */
		OPCODE(fnSetScrollCoordinate),
		OPCODE(fnStandAtAnim),
		OPCODE(fnSetScrollLeftMouse),
		OPCODE(fnSetScrollRightMouse),
		/* 4C */
		OPCODE(fnColour),
		OPCODE(fnFlash),
		OPCODE(fnPreFetch),
		OPCODE(fnGetPlayerSaveData),
		/* 50 */
		OPCODE(fnPassPlayerSaveData),
		OPCODE(fnSendEvent),
		OPCODE(fnAddWalkGrid),
		OPCODE(fnRemoveWalkGrid),
		/* 54 */
		OPCODE(fnCheckForEvent),
		OPCODE(fnPauseForEvent),
		OPCODE(fnClearEvent),
		OPCODE(fnFaceMega),
		/* 58 */
		OPCODE(fnPlaySequence),
		OPCODE(fnShadedSprite),
		OPCODE(fnUnshadedSprite),
		OPCODE(fnFadeUp),
		/* 60 */
		OPCODE(fnDisplayMsg),
		OPCODE(fnSetObjectHeld),
		OPCODE(fnAddSequenceText),
		OPCODE(fnResetGlobals),
		/* 64 */
		OPCODE(fnSetPalette),
		OPCODE(fnRegisterPointerText),
		OPCODE(fnFetchWait),
		OPCODE(fnRelease),
		/* 68 */
		OPCODE(fnPrepareMusic),
		OPCODE(fnSoundFetch),
		OPCODE(fnPrepareMusic),	// Again, apparently
		OPCODE(fnSmackerLeadIn),
		/* 6C */
		OPCODE(fnSmackerLeadOut),
		OPCODE(fnStopAllFx),
		OPCODE(fnCheckPlayerActivity),
		OPCODE(fnResetPlayerActivityDelay),
		/* 70 */
		OPCODE(fnCheckMusicPlaying),
		OPCODE(fnPlayCredits),
		OPCODE(fnSetScrollSpeedNormal),
		OPCODE(fnSetScrollSpeedSlow),
		/* 74 */
		OPCODE(fnRemoveChooser),
		OPCODE(fnSetFxVolAndPan),
		OPCODE(fnSetFxVol),
		OPCODE(fnRestoreGame),
		/* 78 */
		OPCODE(fnRefreshInventory),
		OPCODE(fnChangeShadows)
	};

	_opcodes = opcodes;
}

int32 Logic::executeOpcode(int i, int32 *params) {
	OpcodeProc op = _opcodes[i].proc;

	debug(5, "%s", _opcodes[i].desc);

	return (this->*op) (params);
}

// FIXME: Is the handling of script local variables really alignment-safe?

#define CHECKSTACKPOINTER2 assert(stackPointer2 >= 0 && stackPointer2 < STACK_SIZE);
#define	PUSHONSTACK(x) { stack2[stackPointer2] = (x); stackPointer2++; CHECKSTACKPOINTER2 }
#define POPOFFSTACK(x) { x = stack2[stackPointer2 - 1]; stackPointer2--; CHECKSTACKPOINTER2 }
#define DOOPERATION(x) { stack2[stackPointer2 - 2] = (x); stackPointer2--; CHECKSTACKPOINTER2 }

void Logic::setGlobalInterpreterVariables(int32 *vars) {
	_globals = vars;
}

int Logic::runScript(char *scriptData, char *objectData, uint32 *offset) {
	#define STACK_SIZE		10

	_standardHeader *header = (_standardHeader *) scriptData;
	scriptData += sizeof(_standardHeader) + sizeof(_object_hub);

	// The script data format:
	//	int32_TYPE	1		Size of variable space in bytes
	//	...				The variable space
	//	int32_TYPE	1		numberOfScripts
	//	int32_TYPE	numberOfScripts	The offsets for each script

	// Initialise some stuff

	int ip = 0;			 // Code pointer
	int curCommand,parameter, value; // Command and parameter variables
	int32 stack2[STACK_SIZE];	 // The current stack
	int32 stackPointer2 = 0;	// Position within stack
	int parameterReturnedFromMcodeFunction = 0;	// Allow scripts to return things
	int savedStartOfMcode = 0;	// For saving start of mcode commands

	int count;
	int retVal;
	int caseCount, foundCase;
	int scriptNumber, foundScript;
	const char *tempScrPtr;

	// Get the start of variables and start of code
	debug(5, "Enter interpreter data %x, object %x, offset %d", scriptData, objectData, *offset);

	// FIXME: 'scriptData' and 'variables' used to be const. However,
	// this code writes into 'variables' so it can not be const.

	char *variables = scriptData + sizeof(int32);
	const char *code = scriptData + (int32) READ_LE_UINT32(scriptData) + sizeof(int32);
	uint32 noScripts = (int32) READ_LE_UINT32(code);

	if (*offset < noScripts) {
		ip = READ_LE_UINT32((const int *) code + *offset + 1);
		debug(5, "Start script %d with offset %d", *offset, ip);
	} else {
		ip = *offset;
		debug(5, "Start script with offset %d", ip);
	}

	code += noScripts * sizeof(int32) + sizeof(int32);

#ifdef DONTPROCESSSCRIPTCHECKSUM
	code += sizeof(int32) * 3;
#else
	// Code should nop be pointing at an identifier and a checksum
	const int *checksumBlock = (const int *) code;
	code += sizeof(int32) * 3;

	if (READ_LE_UINT32(checksumBlock) != 12345678) {
		error("Invalid script in object %s", header->name);
		return 0;
	}

	int codeLen = READ_LE_UINT32(checksumBlock + 1);
	int checksum = 0;

	for (count = 0; count < codeLen; count++)
		checksum += (unsigned char) code[count];

	if (checksum != (int32) READ_LE_UINT32(checksumBlock + 2)) {
		error("Checksum error in object %s", header->name);
		return 0;
	}
#endif

	int runningScript = 1;

	while (runningScript) {
		curCommand = code[ip++];

		switch (curCommand) {
		case CP_END_SCRIPT:
			// End the script
			debug(5, "End script",0);
			runningScript = 0;
			break;
		case CP_PUSH_LOCAL_VAR32:
			// Push the contents of a local variable
			Read16ip(parameter);
			debug(5, "Push local var %d (%d)", parameter, *(int32 *) (variables + parameter));
			PUSHONSTACK(*(int32 *) (variables + parameter));
			break;
		case CP_PUSH_GLOBAL_VAR32:
			// Push a global variable
			Read16ip(parameter);
			assert(_globals);
			debug(5, "Push global var %d (%d)", parameter, _globals[parameter]);
			PUSHONSTACK(_globals[parameter]);
			break;
		case CP_POP_LOCAL_VAR32:
			// Pop a value into a local word variable
			Read16ip(parameter);
			POPOFFSTACK(value);
			debug(5, "Pop %d into local var %d", value, parameter);
			*((int32 *) (variables + parameter)) = value;
			break;
		case CP_CALL_MCODE:
			// Call an mcode routine
			Read16ip(parameter);
			assert(parameter <= MAX_FN_NUMBER);
			// amount to adjust stack by (no of parameters)
			Read8ip(value);
			retVal = executeOpcode(parameter, stack2 + stackPointer2 - value);

			stackPointer2 -= value;
			CHECKSTACKPOINTER2

			switch (retVal & 7) {
			case IR_STOP:
				// Quit out for a cycle
				*offset = ip;
				return 0;
			case IR_CONT:
				// Continue as normal
				break;
			case IR_TERMINATE:
				// Return without updating the
				// offset
				return 2;
			case IR_REPEAT:
				// Return setting offset to
				// start of this function call
				*offset = savedStartOfMcode;
				return 0;
			case IR_GOSUB:
				// that's really neat
				*offset = ip;
				return 2;
			default:
				assert(false);
			}
			parameterReturnedFromMcodeFunction = retVal >> 3;
			break;
		case CP_PUSH_LOCAL_ADDR:
			// push the address of a local variable
			Read16ip(parameter);
			debug(5, "Push address of local variable %d (%x)", parameter, _vm->_memory->ptrToInt((const uint8 *) (variables + parameter)));
			PUSHONSTACK(_vm->_memory->ptrToInt((uint8 *) (variables + parameter)));
			break;
		case CP_PUSH_INT32:
			// Push a long word value on to the stack
			Read32ip(parameter);
			debug(5, "Push int32 %d (%x)", parameter, parameter);
			PUSHONSTACK(parameter);
			break;
		case CP_SKIPONFALSE:
			// Skip if the value on the stack is false
			Read32ipLeaveip(parameter);
			POPOFFSTACK(value);
			debug(5, "Skip %d if %d is false", parameter, value);
			if (value)
				ip += sizeof(int32);
			else
				ip += parameter;
			break;
		case CP_SKIPALWAYS:
			// skip a block
			Read32ipLeaveip(parameter);
			debug(5, "Skip %d", parameter);
			ip += parameter;
			break;
		case CP_SWITCH:
			// 9 switch
			POPOFFSTACK(value);
			Read32ip(caseCount);

			// Search the cases
			foundCase = 0;
			for (count = 0; count < caseCount && !foundCase; count++) {
				if (value == (int32) READ_LE_UINT32(code + ip)) {
					// We have found the case, so lets
					// jump to it
					foundCase = 1;
					ip += READ_LE_UINT32(code + ip + sizeof(int32));
				} else
					ip += sizeof(int32) * 2;
			}

			// If we found no matching case then use the
			// default

			if (!foundCase)
				ip += READ_LE_UINT32(code + ip);

			break;
		case CP_ADDNPOP_LOCAL_VAR32:
			Read16ip(parameter);
			POPOFFSTACK(value);
			*((int32 *) (variables + parameter)) += value;
			debug(5, "+= %d into local var %d->%d", value, parameter, *(int32 *) (variables + parameter));
			break;
		case CP_SUBNPOP_LOCAL_VAR32:
			Read16ip(parameter);
			POPOFFSTACK(value);
			*((int32 *) (variables + parameter)) -= value;
			debug(5, "-= %d into local var %d->%d", value, parameter, *(int32 *) (variables + parameter));
			break;
		case CP_SKIPONTRUE:
			// Skip if the value on the stack is TRUE
			Read32ipLeaveip(parameter);
			POPOFFSTACK(value);
			debug(5, "Skip %d if %d is false", parameter, value);
			if (!value)
				ip += sizeof(int32);
			else
				ip += parameter;
			break;
		case CP_POP_GLOBAL_VAR32:
			// Pop a global variable
			Read16ip(parameter);
			POPOFFSTACK(value);
			debug(5, "Pop %d into global var %d", value, parameter);

#ifdef TRACEGLOBALVARIABLESET
			TRACEGLOBALVARIABLESET(parameter, value);
#endif

			_globals[parameter] = value;
			break;
		case CP_ADDNPOP_GLOBAL_VAR32:
			// Add and pop a global variable
			Read16ip(parameter);
			POPOFFSTACK(value);
			_globals[parameter] += value;
			debug(5, "+= %d into global var %d->%d", value, parameter, _globals[parameter]);
			break;
		case CP_SUBNPOP_GLOBAL_VAR32:
			// Sub and pop a global variable
			Read16ip(parameter);
			POPOFFSTACK(value);
			_globals[parameter] -= value;
			debug(5, "-= %d into global var %d->%d", value, parameter, _globals[parameter]);
			break;
		case CP_DEBUGON:
			// Turn debugging on
			_debugFlag = true;
			break;
		case CP_DEBUGOFF:
			// Turn debugging on
			_debugFlag = false;
			break;
		case CP_QUIT:
			// Quit out for a cycle
			*offset = ip;
			return 0;
		case CP_TERMINATE:
			// Quit out immediately without affecting the offset
			// pointer
			return 3;

		// Operators

		case OP_ISEQUAL:
			// '=='
			debug(5, "%d == %d -> %d",
				stack2[stackPointer2 - 2],
				stack2[stackPointer2 - 1],
				stack2[stackPointer2 - 2] == stack2[stackPointer2 - 1]);
			DOOPERATION(stack2[stackPointer2 - 2] == stack2[stackPointer2 - 1]);
			break;
		case OP_PLUS:
			// '+'
			debug(5, "%d + %d -> %d",
				stack2[stackPointer2 - 2],
				stack2[stackPointer2 - 1],
				stack2[stackPointer2 - 2] + stack2[stackPointer2 - 1]);
			DOOPERATION(stack2[stackPointer2 - 2] + stack2[stackPointer2 - 1]);
			break;
		case OP_MINUS:
			// '-'
			debug(5, "%d - %d -> %d",
				stack2[stackPointer2 - 2],
				stack2[stackPointer2 - 1],
				stack2[stackPointer2 - 2] - stack2[stackPointer2 - 1]);
			DOOPERATION(stack2[stackPointer2 - 2] - stack2[stackPointer2 - 1]);
			break;
		case OP_TIMES:
			// '*'
			debug(5, "%d * %d -> %d",
				stack2[stackPointer2 - 2],
				stack2[stackPointer2 - 1],
				stack2[stackPointer2 - 2] * stack2[stackPointer2 - 1]);
			DOOPERATION(stack2[stackPointer2 - 2] * stack2[stackPointer2 - 1]);
			break;
		case OP_DIVIDE:
			// '/'
			debug(5, "%d / %d -> %d",
				stack2[stackPointer2 - 2],
				stack2[stackPointer2 - 1],
				stack2[stackPointer2 - 2] / stack2[stackPointer2 - 1]);
			DOOPERATION(stack2[stackPointer2 - 2] / stack2[stackPointer2 - 1]);
			break;
		case OP_NOTEQUAL:
			// '!='
			debug(5, "%d != %d -> %d",
				stack2[stackPointer2 - 2],
				stack2[stackPointer2 - 1],
				stack2[stackPointer2 - 2] != stack2[stackPointer2 - 1]);
			DOOPERATION(stack2[stackPointer2 - 2] != stack2[stackPointer2 - 1]);
			break;
		case OP_ANDAND:
			// '&&'
			debug(5, "%d && %d -> %d",
				stack2[stackPointer2 - 2],
				stack2[stackPointer2 - 1],
				stack2[stackPointer2 - 2] && stack2[stackPointer2 - 1]);
			DOOPERATION(stack2[stackPointer2 - 2] && stack2[stackPointer2 - 1]);
			break;
		case OP_GTTHAN:
			// '>'
			debug(5, "%d > %d -> %d",
				stack2[stackPointer2 - 2],
				stack2[stackPointer2 - 1],
				stack2[stackPointer2 - 2] > stack2[stackPointer2 - 1]);
			DOOPERATION(stack2[stackPointer2 - 2] > stack2[stackPointer2 - 1]);
			break;
		case OP_LSTHAN:
			// '<'
			debug(5, "%d < %d -> %d",
				stack2[stackPointer2 - 2],
				stack2[stackPointer2 - 1],
				stack2[stackPointer2 - 2] < stack2[stackPointer2 - 1]);
			DOOPERATION(stack2[stackPointer2 - 2] < stack2[stackPointer2 - 1]);
			break;
		case CP_JUMP_ON_RETURNED:
			// Jump to a part of the script depending on
			// the return value from an mcode routine

			// Get the maximum value
			Read8ip(parameter);
			ip += READ_LE_UINT32(code + ip + parameterReturnedFromMcodeFunction * 4);
			break;
		case CP_TEMP_TEXT_PROCESS:
			// Process a text line
			// This was apparently used in Linc
			Read32ip(parameter);
			debug(5, "Process text id %d", parameter);
			break;
		case CP_SAVE_MCODE_START:
			// Save the start position on an mcode instruction in
			// case we need to restart it again
			savedStartOfMcode = ip - 1;
			break;
		case CP_RESTART_SCRIPT:
			// Start the script again
			// Do a ip search to find the script we are running

			tempScrPtr = scriptData + READ_LE_UINT32(scriptData) + sizeof(int32);
			scriptNumber = 0;
			foundScript = 0;

			for (count = 1; count < (int) noScripts && !foundScript; count++) {
				if (ip < ((const int *) tempScrPtr)[count + 1]) {
					scriptNumber = count - 1;
					foundScript = 1;
				}
			}

			if (!foundScript)
				scriptNumber = count - 1;

			// So we know what script we are running, lets restart
			// it

			ip = ((const int *) tempScrPtr)[scriptNumber + 1];
			break;
		case CP_PUSH_STRING:
			// Push the address of a string on to the stack
			// Get the string size
			Read8ip(parameter);

			// ip points to the string
			PUSHONSTACK(_vm->_memory->ptrToInt((const uint8 *) (code + ip)));
			ip += (parameter + 1);
			break;
		case CP_PUSH_DEREFERENCED_STRUCTURE:
			// Push the address of a dereferenced structure
			Read32ip(parameter);
			debug(5, "Push address of far variable (%x)", _vm->_memory->ptrToInt((const uint8 *) (objectData + sizeof(int32) + sizeof(_standardHeader) + sizeof(_object_hub) + parameter)));
			PUSHONSTACK(_vm->_memory->ptrToInt((const uint8 *) (objectData + sizeof(int32) + sizeof(_standardHeader) + sizeof(_object_hub) + parameter)));
			break;
		case OP_GTTHANE:
			// '>='
			debug(5, "%d >= %d -> %d",
				stack2[stackPointer2 - 2],
				stack2[stackPointer2 - 1],
				stack2[stackPointer2 - 2] >= stack2[stackPointer2 - 1]);
			DOOPERATION(stack2[stackPointer2 - 2] >= stack2[stackPointer2 - 1]);
			break;
		case OP_LSTHANE:
			// '<='
			debug(5, "%d <= %d -> %d",
				stack2[stackPointer2 - 2],
				stack2[stackPointer2 - 1],
				stack2[stackPointer2 - 2] <= stack2[stackPointer2 - 1]);
			DOOPERATION(stack2[stackPointer2 - 2] <= stack2[stackPointer2 - 1]);
			break;
		case OP_OROR:
			// '||'
			debug(5, "%d || %d -> %d",
				stack2[stackPointer2 - 2],
				stack2[stackPointer2 - 1],
				stack2[stackPointer2 - 2] || stack2[stackPointer2 - 1]);
			DOOPERATION (stack2[stackPointer2 - 2] || stack2[stackPointer2 - 1]);
			break;
		default:
			error("Interpreter error: Invalid token %d", curCommand);
			return 3;
		}
	}

	return 1;
}

} // End of namespace Sword2
