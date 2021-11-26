/////////////////////////////////////////////////////////
//                                                     //
//                       _oo0oo_                       //
//                      o8888888o                      //
//                      88" . "88                      //
//                      (| -_- |)                      //
//                      0\  =  /0                      //
//                    ___/`---'\___                    //
//                  .' \\|     |// '.                  //
//                 / \\|||  :  |||// \                 //
//                / _||||| -:- |||||- \                //
//               |   | \\\  -  /// |   |               //
//               | \_|  ''\---/''  |_/ |               //
//               \  .-\__  '-'  ___/-. /               //
//             ___'. .'  /--.--\  `. .'___             //
//          ."" '<  `.___\_<|>_/___.' >' "".           //
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |         //
//         \  \ `_.   \_ __\ /__ _/   .-` /  /         //
//     =====`-.____`.___ \_____/___.-`___.-'=====      //
//                       `=---='                       //
//                                                     //
//                                                     //
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~     //
//                                                     //
//            KHÔNG BUG!        KHÔNG CRASH!           //
//                                                     //
/////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////
//  Authors:                                           //
//  - Harding Adonis                                   //
//  - Nguyễn Hoàng Hy                                  //
/////////////////////////////////////////////////////////

#include <Core/ButtonImage.hpp>

ButtonImage::ButtonImage(sf::Texture& textureNormal, sf::Texture& textureHover) :
	m_textureNormal(textureNormal),
	m_textureHover(textureHover),
	m_isMouseClicked(false)
{
	init();
}

void ButtonImage::setPosition(float x, float y)
{
	m_sprite.setPosition(x, y);
}

void ButtonImage::handleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::EventType::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Button::Left)
		{
			m_isMouseClicked = true;
		}
	}
}

void ButtonImage::draw(sf::RenderTarget& renderer) const
{
	renderer.draw(m_sprite);
}

bool ButtonImage::isButtonPressed(sf::Window& window)
{
	if (m_sprite.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
	{
		m_sprite.setTexture(m_textureHover);

		if (m_isMouseClicked)
		{
			m_isMouseClicked = false;

			return true;
		}
	}
	else
	{
		m_sprite.setTexture(m_textureNormal);
	}

	m_isMouseClicked = false;

	return false;
}

void ButtonImage::init()
{
	m_sprite.setTexture(m_textureNormal);
	m_sprite.setOrigin(sf::Vector2f(m_textureNormal.getSize() / 2u));
}