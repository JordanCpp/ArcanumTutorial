/*
Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#include <Pollux/Events/Handler.hpp>

using namespace Pollux;

Handler::Handler() :
	_Current(NULL),
	_Widget(NULL)
{
}

void Handler::Add(Screen* screen, const std::string& name)
{
	_Screens.insert(std::make_pair(name, screen));
}

void Handler::Active(const std::string& name)
{
	_Current = _Screens[name];
}

void Handler::Show()
{
	if (_Current)
	{
		_Current->Show();
	}
}

void Handler::Handle(const Event& event)
{
	if (_Widget)
	{
		_Widget->State(Widget::StateNormal);
	}

	if (event.Type == IsEventMove)
	{
		Point pos(event.Move.PosX, event.Move.PosY);

		Widget* p = _Current->GetForm()->Contains(pos);

		if (p)
		{
			p->State(Widget::StateHover);
			p->OnHover(pos);

			_Widget = p;
		}
	}
}
