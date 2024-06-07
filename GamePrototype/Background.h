#pragma once
#include <Texture.h>

class Background final
{
public:
	explicit Background(const std::string& filePath);

	virtual ~Background();
	Background(const Background& other) = delete;
	Background& operator=(const Background& other) = delete;
	Background(Background&& other) = delete;
	Background operator=(Background&& other) = delete;

	int GetWidth() const;
	int GetHeight() const;

	void Draw() const;

private:
	const Texture* m_pBackground;

};
