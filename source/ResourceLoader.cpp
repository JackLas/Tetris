#include "ResourceLoader.hpp"
#include <fstream>

#include <iostream>

ResourceLoader::ResourceLoader(const std::string resourcePack): 
resourcePack(resourcePack)
{
}

ResourceLoader::~ResourceLoader()
{
}

sf::Texture ResourceLoader::loadTexture(const std::string name)
{
	sf::Texture texture;

	size_t size;
	byte *data = load(name, &size);

	texture.loadFromMemory(data, size);

	delete[] data;
	return texture;
}

sf::Font ResourceLoader::loadFont(const std::string name)
{
	sf::Font font;

	size_t size;
	byte *data = load(name, &size);

	font.loadFromMemory(data, size);

	delete[] data;
	return font;

}

byte* ResourceLoader::load(const std::string fileName, size_t *size)
{
	std::ifstream rp(resourcePack, std::ios::binary);
	if(!rp.is_open())
		return nullptr;

	byte *data = nullptr;
	while(true)
	{
		size_t fileNameSize;
		if(!rp.read((byte*)&fileNameSize, sizeof(size_t)))
			break; // loop exit

		char tmp;
		std::string curFileName;
		for(unsigned int i = 0; i < fileNameSize; ++i)
		{
			rp.read((byte*)&tmp, sizeof(byte));
			curFileName += tmp;
		}

		size_t curFileSize;
		rp.read((byte*)&curFileSize, sizeof(size_t));

		if(curFileName == fileName)
		{
			*size = curFileSize;
			data = new byte[curFileSize];
			for(unsigned int i = 0; i < curFileSize; ++i)
			{
				rp.read(&tmp, sizeof(byte));
				data[i] = tmp;
			}
			break;
		}
		else rp.seekg(curFileSize, std::ios::cur);
	}
	rp.close();
	return data;
}