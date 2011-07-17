/*****************************************************************************
 * Licensed to Qualys, Inc. (QUALYS) under one or more
 * contributor license agreements. See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * QUALYS licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * *****************************************************************************/

/*****
 * Author: Sergey Shekyan sshekyan@qualys.com
 *         Victor Agababov vagababov@gmail.com
 *
 * Slow HTTP attack  vulnerability test tool
 *  http://code.google.com/p/slowhttptest/
 *
 *  Simple logging
 *****/



#ifndef _SLOWLOG_H_
#define _SLOWLOG_H_
namespace slowhttptest {
void slowlog_init(unsigned int debug_level, const char* file_name);
void slowlog(unsigned int lvl, const char* format, ...);
void log_fatal(const char* format, ...);

void check(bool f, const char* message);
template <class T> T* check_not_null(T* p, const char* message) {
  check(p != 0, message);
  return p;
}
}  // namespace slowhttptest

#define CHECK_NOTNULL(p) slowhttptest::check_not_null(p, #p" is NULL")

#endif  // _SLOWLOG_H_
