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

#include <Arcanum/Managers/SpriteManager.hpp>
#include <Pollux/Readers/MemoryReader.hpp>

using namespace Arcanum;
using namespace Pollux;

SpriteManager::SpriteManager(Canvas& canvas, const Color& colorKey, FileManager& fileManager, ImageLoader& imageLoader, Pollux::TextureManager& textureManager) :
	_TextureManager(textureManager),
	_ColorKey(colorKey),
	_Canvas(canvas),
	_FileManager(fileManager),
	_ImageLoader(imageLoader)
{
}

SpriteManager::~SpriteManager()
{
}

const Texture* SpriteManager::Get(const std::string& path) const
{
	const Texture* result = _TextureManager.Get(path);

	if (result == NULL)
	{
		_ImageLoader.Load(_FileManager.File(path));

		result = new Texture(_Canvas, _ImageLoader.Size(), _ImageLoader.Bpp(), _ImageLoader.Pixels(), _ColorKey);

		_TextureManager.Add(path, result);

		return result;
	}

	return result;
}
