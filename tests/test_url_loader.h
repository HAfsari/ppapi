// Copyright (c) 2010 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef PAPPI_TESTS_TEST_URL_LOADER_H_
#define PAPPI_TESTS_TEST_URL_LOADER_H_

#include <string>

#include "ppapi/tests/test_case.h"

namespace pp {
class FileIO_Dev;
class URLLoader_Dev;
class URLRequestInfo_Dev;
}

class TestURLLoader : public TestCase {
 public:
  explicit TestURLLoader(TestInstance* instance) : TestCase(instance) {}

  // TestCase implementation.
  virtual bool Init();
  virtual void RunTest();
  
 private:
  std::string ReadEntireFile(pp::FileIO_Dev* file_io, std::string* data);
  std::string ReadEntireResponseBody(pp::URLLoader_Dev* loader,
                                     std::string* body);
  std::string LoadAndCompareBody(const pp::URLRequestInfo_Dev& request,
                                 const std::string& expected_body);

  std::string TestBasicGET();
  std::string TestBasicPOST();
  std::string TestCompoundBodyPOST();
  std::string TestEmptyDataPOST();
  std::string TestCustomRequestHeader();
  std::string TestIgnoresBogusContentLength();
  std::string TestStreamToFile();
};

#endif  // PAPPI_TESTS_TEST_URL_LOADER_H_
