#include <QtGlobal>

#ifdef Q_OS_IOS

#ifndef MOBILESYNTHVIEWCONTROLLERRC1_HPP
#define MOBILESYNTHVIEWCONTROLLERRC1_HPP

#include "synth/controller.h"

namespace mobilesynthview
{
  struct WidgetImpl;
  class Widget
  {
    WidgetImpl* impl;
  public:
    Widget();
    ~Widget();
    void setController(synth::Controller * ctl);
  };
}

#endif // MOBILESYNTHVIEWCONTROLLERRC1_HPP
#endif // MOBILESYNTHVIEWCONTROLLERRC1_HPP

