// Copyright (c) 2010 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef PPAPI_CPP_WIDGET_H_
#define PPAPI_CPP_WIDGET_H_

#include "ppapi/c/pp_stdint.h"
#include "ppapi/cpp/resource.h"

typedef struct _pp_Rect PP_Rect;
typedef struct _pp_Event PP_Event;

namespace pp {

class ImageData;

// This is the base class for widget elements.  As such, it can't be created
// directly.
class Widget : public Resource {
 public:
  // PPB_Widget methods:
  bool Paint(const PP_Rect& rect, ImageData* image);
  bool HandleEvent(const PP_Event& event);
  bool GetLocation(PP_Rect* location);
  void SetLocation(const PP_Rect& location);

 protected:
  Widget();
};

}  // namespace pp

#endif  // PPAPI_CPP_WIDGET_H_