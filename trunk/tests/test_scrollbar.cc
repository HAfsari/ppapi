// Copyright (c) 2010 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ppapi/tests/test_scrollbar.h"

#include "ppapi/c/pp_event.h"
#include "ppapi/c/pp_rect.h"
#include "ppapi/cpp/instance.h"
#include "ppapi/tests/test_instance.h"

REGISTER_TEST_CASE(Scrollbar);

TestScrollbar::TestScrollbar(TestInstance* instance)
    : TestCase(instance),
      scrollbar_value_changed_(false),
      scrollbar_(*instance, true) {
}

void TestScrollbar::RunTest() {
  instance_->LogTest("HandleEvent", TestHandleEvent());
}

void TestScrollbar::ScrollbarValueChanged(pp::Scrollbar scrollbar,
                                          uint32_t value) {
  if (scrollbar == scrollbar_)
    scrollbar_value_changed_ = true;
}

std::string TestScrollbar::TestHandleEvent() {
  PP_Rect location;
  location.size.width = location.size.height  = 1000;
  scrollbar_.SetLocation(location);

  scrollbar_.SetDocumentSize(10000);

  PP_Event event;
  event.size = sizeof(event);
  event.type = PP_EVENT_TYPE_KEYDOWN;
  event.u.key.normalizedKeyCode = 0x28; // VKEY_DOWN
  scrollbar_.HandleEvent(event);

  return scrollbar_value_changed_ ?
      "" : "Didn't get callback for scrollbar value change";
}