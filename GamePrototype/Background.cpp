#include "pch.h"
#include "Background.h"

Background::Background(const std::string& filePath)
	//: m_BackgroundState{BackgroundState::Turquoise}
{	
	m_pBackground = new Texture(filePath);
}

Background::~Background()
{
	delete m_pBackground;
}

void Background::Draw() const
{
	m_pBackground->Draw();

}

int Background::GetWidth() const
{
	return 10; // m_pBackground->GetWidth();
}

int Background::GetHeight() const
{
	return 10; // m_pBackground->GetHeight();
}


