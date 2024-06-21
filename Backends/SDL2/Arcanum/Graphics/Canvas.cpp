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

#include <Arcanum/Graphics/Canvas.hpp>
#include <Arcanum/Graphics/Texture.hpp>
#include <stdexcept>
#include <cassert>

using namespace Arcanum;

Canvas::Canvas(const Point& size, const String& title) :
	_Running(true),
	_Window(nullptr),
	_Render(nullptr)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		throw std::runtime_error(SDL_GetError());

	_Window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, size.x, size.y, SDL_WINDOW_SHOWN);

	if (!_Window)
		throw std::runtime_error(SDL_GetError());

	_Render = SDL_CreateRenderer(_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (!_Render)
		throw std::runtime_error(SDL_GetError());
}

Canvas::~Canvas()
{
	SDL_DestroyRenderer(_Render);
	SDL_DestroyWindow(_Window);
	SDL_Quit();
}

void Canvas::Present()
{
	SDL_RenderPresent(_Render);
}

void Canvas::Draw(Texture* texture, const Point& dstPos, const Point& dstSize, const Point& srcPos, const Point& srcSize)
{
	assert(texture != nullptr);
	assert(dstPos.x >= 0);
	assert(dstPos.y >= 0);
	assert(dstSize.x > 0);
	assert(dstSize.y > 0);
	assert(srcPos.x >= 0);
	assert(srcPos.y >= 0);
	assert(srcSize.x > 0);
	assert(srcSize.y > 0);

	SDL_Rect dstRect = { dstPos.x ,dstPos.y, dstSize.x, dstSize.y };
	SDL_Rect srcRect = { srcPos.x ,srcPos.y, srcSize.x, srcSize.y };

	Texture* impl = (Texture*)texture;

	SDL_RenderCopy(_Render, impl->GetTextureImpl(), &srcRect, &dstRect);
}

void Canvas::Draw(Texture* texture, const Point& dstPos)
{
	Draw(texture, dstPos, texture->Size(), Point(0, 0), texture->Size());
}

bool Canvas::GetEvent(Event& dstEvent)
{
	SDL_Event event = { 0 };

	if (_Running)
	{
		SDL_PollEvent(&event);

		if (event.type == SDL_QUIT)
		{
			dstEvent.Type = IsEventQuit;
		}
		else if (event.type == SDL_MOUSEMOTION)
		{
			dstEvent.Type = IsEventMove;
			dstEvent.Move.PosX = event.motion.x;
			dstEvent.Move.PosY = event.motion.y;
		}
	}

	return _Running;
}

void Canvas::StopEvent()
{
	_Running = false;
}

SDL_Renderer* Canvas::GetRenderImpl()
{
	return _Render;
}
