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

#include <Arcanum/Loaders/ImageLoader.hpp>
#include <stdexcept>

#define STB_IMAGE_IMPLEMENTATION
#define STBI_NO_THREAD_LOCALS
#define STBI_NO_SIMD
#include "../../dependencies/stb/stb_image.h"

using namespace Arcanum;

ImageLoader::ImageLoader() :
	_Bpp(0),
	_Pixels(NULL)
{
}

void ImageLoader::Load(const std::vector<uint8_t>& data)
{
	if (_Pixels != NULL)
	{
		stbi_image_free(_Pixels);
	}

	_Pixels = (uint8_t*)stbi_load_from_memory((stbi_uc*)&data[0], (int)data.size(), &_Size.x, &_Size.y, &_Bpp, STBI_default);

	if (!_Pixels)
	{
		throw std::runtime_error("Can't load file");
	}
}

int ImageLoader::Bpp()
{
	return _Bpp;
}

uint8_t* ImageLoader::Pixels()
{
	return _Pixels;
}

const Point& ImageLoader::Size()
{
	return _Size;
}
