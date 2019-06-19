#!/usr/bin/python3

# Copyright (c) 2019 The Khronos Group Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from collections import OrderedDict
from collections import namedtuple

import argparse
import sys
import urllib
import xml.etree.ElementTree as etree
import urllib.request

# parse_xml - Helper function to parse the XML file from a URL or local file.
def parse_xml(path):
    file = urllib.request.urlopen(path) if path.startswith("http") else open(path, 'r')
    with file:
        tree = etree.parse(file)
        return tree

# noneStr - returns string argument, or "" if argument is None.
def noneStr(s):
    if s:
        return s
    return ""

# GetCopyrightHeader - This is the shared copyright header for all files.
def GetCopyrightHeader():
    return """/*
 * Copyright (c) 2016-2019 The Khronos Group Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * OpenCL is a trademark of Apple Inc. used under license by Khronos.
 */
"""

# GetHeaderApi_h - This is the file header for the API header file.
def GetHeaderApi_h():
    return GetCopyrightHeader() + """
#pragma once
#include <CL/cl.h>
#include <CL/cl_ext.h>

"""

# GetHeaderApi_cpp - This is the file header for the API cpp file.
def GetHeaderApi_cpp():
    return GetCopyrightHeader() + """
#include "recorder.h"

"""

# AddRecorderApi_h - Adds one API to the API header file.
def AddRecorderApi_h(file, api):
    file.write("""///////////////////////////////////////////////////////////////////////////////

""")
    # Generate the arguments structure:
    #   struct clApiName_args { args; }
    # Also generate the struct extern:
    #   extern struct clApiName_args;
    if len(api.Params) > 0:
        file.write('struct ' + api.Name + '_args\n')
        params = '{\n'
        for param in api.Params:
            # This is a special case, to turn:
            #   void* svm_pointers[]
            # into:
            #   void** svm_pointers
            if param.TypeEnd == '[]':
                params += '    ' + param.Type + '* ' + param.Name + ';\n'
            else:
                params += '    ' + param.Type + ' ' + param.Name + param.TypeEnd + ';\n'
        params += '};\n'
        file.write(params)
        file.write('extern struct ' + api.Name + '_args g_' + api.Name + ';\n\n')

    # Generate the recorder API prototype:
    file.write('CL_API_ENTRY ' + api.RetType + ' CL_API_CALL rec' + api.Name)
    if len(api.Params) > 0:
        params = '(\n'
        params += ',\n'.join('    ' + param.Type + ' ' + param.Name + param.TypeEnd
                             for param in api.Params)
        params += ');\n\n';
        file.write(params)
    else:
        file.write('(void);\n\n')

# AddRecorderApi_cpp - Adds one API to the API cpp file.
def AddRecorderApi_cpp(file, api):
    file.write("""///////////////////////////////////////////////////////////////////////////////

""")
    if len(api.Params) > 0:
        file.write('struct ' + api.Name + '_args g_' + api.Name + ';\n\n')

    file.write('CL_API_ENTRY ' + api.RetType + ' CL_API_CALL rec' + api.Name)
    if len(api.Params) > 0:
        params = '(\n'
        params += ',\n'.join('    ' + param.Type + ' ' + param.Name + param.TypeEnd
                             for param in api.Params)
        params += ')\n'
        file.write(params)
    else:
        file.write('(void)\n')

    file.write('{\n')
    if len(api.Params) > 0:
        params = ''
        params += ''.join('    g_' + api.Name + '.' + param.Name + ' = ' + param.Name + ';\n'
                          for param in api.Params)
        file.write(params)
    if api.RetType == 'void':
        file.write('    // no return value\n')
    elif api.RetType == 'cl_platform_id':
        file.write('    return g_Platform;\n')
    elif api.RetType == 'cl_device_id':
        file.write('    return g_Device;\n')
    elif api.RetType == 'cl_context':
        file.write('    return g_Context;\n')
    elif api.RetType == 'cl_command_queue':
        file.write('    return g_CommandQueue;\n')
    elif api.RetType == 'cl_mem':
        file.write('    return g_Mem;\n')
    elif api.RetType == 'cl_program':
        file.write('    return g_Program;\n')
    elif api.RetType == 'cl_event':
        file.write('    return g_Event;\n')
    elif api.RetType == 'cl_sampler':
        file.write('    return g_Sampler;\n')
    else:
        file.write('    return (' + api.RetType + ')0;\n')
    file.write('}\n\n')

# AddTestTemplate_cpp - Adds one API to the test templates file.
def AddTestTemplate_cpp(file, api):
    file.write("""///////////////////////////////////////////////////////////////////////////////

""")

    file.write('TEST(Category, ' + api.Name + ') {\n')
    file.write('    cl_int errorCode = CL_SUCCESS;\n\n')
    file.write('    // possible test local variables:\n')

    if len(api.Params) > 0:
        params = ''
        params += ''.join('    //   ' + param.Type + ' ' + param.Name + param.TypeEnd + ';\n'
                          for param in api.Params)
        file.write(params)

    file.write('\n')
    file.write('    struct ' + api.Name + '_args testArgs = {\n')
    file.write('        // test args:\n')

    if len(api.Params) > 0:
        params = ''
        params += ''.join('        //   ' + param.Name + ',\n'
                          for param in api.Params)
        file.write(params)

    file.write('    };\n\n')
    file.write('    memset(&g_' + api.Name + ', 0xCC, sizeof(g_' + api.Name + '));\n\n')
    file.write('    ' + api.RetType + ' ret = ' + api.Name + '(\n')

    if len(api.Params) > 0:
        params = ''
        params += ',\n'.join('        testArgs.' + param.Name
                             for param in api.Params)
        params += ');\n\n';
        file.write(params)
    else:
        file.write('        );\n\n')

    file.write('    //EXPECT_EQ( ret, ... );\n')
    if len(api.Params) > 0:
        params = ''
        params += ''.join('    EXPECT_EQ( testArgs.' + param.Name + ', g_' + api.Name + '.' + param.Name + ' );\n'
                          for param in api.Params)
        file.write(params)

    file.write('}\n\n')

if __name__ == "__main__":
    parser = argparse.ArgumentParser()

    parser.add_argument('-registry', action='store',
                        default='cl.xml',
                        help='Use specified registry file instead of cl.xml')
    parser.add_argument('-o', action='store', dest='directory',
                        default='.',
                        help='Create target and related files in specified directory')

    args = parser.parse_args()

    specpath = args.registry
    #specpath = "https://raw.githubusercontent.com/KhronosGroup/OpenCL-Registry/master/xml/cl.xml"

    print('Parsing XML file from: ' + specpath)
    spec = parse_xml(specpath)

    # Generate the API functions dictionary:
    apidict = OrderedDict()
    ApiSignature = namedtuple('ApiSignature', 'Name RetType Params')
    ApiParam = namedtuple('ApiParam', 'Type TypeEnd Name')
    print('Generating API dictionary...')
    for command in spec.findall('commands/command'):
        proto = command.find('proto')
        ret = noneStr(proto.text)
        name = ""
        params = ""
        for elem in proto:
            if elem.tag == 'name':
                name = noneStr(elem.text) + noneStr(elem.tail)
            else:
                ret = ret + noneStr(elem.text) + noneStr(elem.tail)
        ret = ret.strip()
        name = name.strip()

        plist = []
        for param in command.findall('param'):
            ptype = noneStr(param.text)
            ptypeend = ""
            pname = ""
            for elem in param:
                if elem.tag == 'name':
                    pname = noneStr(elem.text)
                    ptypeend = noneStr(elem.tail)
                else:
                    ptype = ptype + noneStr(elem.text) + noneStr(elem.tail)
            ptype = ptype.strip()
            ptypeend = ptypeend.strip()
            pname = pname.strip()
            plist.append(ApiParam(ptype, ptypeend, pname))
        apidict[name] = ApiSignature(name, ret, plist)

    # Create the recorder files from the API dictionary:

    recApi_h = open(args.directory + '/api_generated.h', 'w')
    recApi_h.write(GetHeaderApi_h())

    recApi_cpp = open(args.directory + '/api_generated.cpp', 'w')
    recApi_cpp.write(GetHeaderApi_cpp())

    print('Generating Recorder ICD APIs...')
    for feature in spec.findall('feature/require'):
        for function in feature.findall('command'):
            name = function.get('name')
            api = apidict[name]
            AddRecorderApi_h(recApi_h, api)
            AddRecorderApi_cpp(recApi_cpp, api)

    # Also create test templates from the API dictionary:

    testTemplate_cpp = open(args.directory + '/test_templates.cpp', 'w')
    testTemplate_cpp.write(GetCopyrightHeader())

    print('Generating Test Templates...')
    for feature in spec.findall('feature/require'):
        for function in feature.findall('command'):
            name = function.get('name')
            api = apidict[name]
            AddTestTemplate_cpp(testTemplate_cpp, api)

    #for extension in tree.findall('extensions/extension'):
    #    print(extension.get('name'))
    #    for func in extension.findall('require/command'):
    #        print('    '+func.get('name'))
