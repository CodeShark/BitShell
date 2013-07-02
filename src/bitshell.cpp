///////////////////////////////////////////////////////////////////////////////
//
// bitshell.cpp
//
// Copyright (c) 2013 Eric Lombrozo
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include "bitcoind_commands.h"

#include <command_interpreter.h>
#include <iostream>

// main function
int main(int argc, char** argv)
{
    initCommands();
    addCommand("addmultisigaddress", &bitcoind_addmultisigaddress);
    addCommand("addnode", &bitcoind_addnode);
    addCommand("backupwallet", &bitcoind_backupwallet);
    addCommand("createmultisig", &bitcoind_createmultisig);
    addCommand("getinfo", &bitcoind_getinfo);
    addCommand("getblockcount", &bitcoind_getblockcount);
    addCommand("getbalance", &bitcoind_getbalance);
    return startInterpreter(argc, argv);
}
