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

#include <Scenes/AboutScene.hpp>
#include <Utils/CheckInput.hpp>

#if defined (SFML_SYSTEM_WINDOWS)
#include <Windows.h>
#endif

AboutScene::AboutScene(GameData::Ref gameData) :
	m_gameData(gameData),
	m_isMouseClicked(false)
{
}

void AboutScene::init()
{
	// Setup for background
	m_background.setTexture(m_gameData->assetsManager.getTexture(3));
	m_background.setOrigin(sf::Vector2f(m_gameData->assetsManager.getTexture(3).getSize() / 2u));
	m_background.setPosition(450.f, 250.f);
	m_background.setColor(sf::Color(24, 29, 49, 255));

	// Setup adonis qrcode
	m_adonis_qrcode.setTexture(m_gameData->assetsManager.getTexture(4));
	m_adonis_qrcode.setOrigin(sf::Vector2f(m_gameData->assetsManager.getTexture(4).getSize() / 2u));
	m_adonis_qrcode.setPosition(145.f, 220.f);

	// Setup hy qrcode
	m_hy_qrcode.setTexture(m_gameData->assetsManager.getTexture(5));
	m_hy_qrcode.setOrigin(sf::Vector2f(m_gameData->assetsManager.getTexture(5).getSize() / 2u));
	m_hy_qrcode.setPosition(755.f, 220.f);

	// Setup adonis button
	m_adonis.setFont(m_gameData->assetsManager.getFont());
	m_adonis.setString("HARDING ADONIS");
	m_adonis.setStyle(sf::Text::Style::Bold);
	m_adonis.setCharacterSize(20);
	m_adonis.setOrigin(m_adonis.getLocalBounds().width / 2, m_adonis.getLocalBounds().height / 2);
	m_adonis.setPosition(145.f, 320.f);
	m_adonis.setFillColor(sf::Color(24, 29, 49, 255));

	// Setup hy button
	m_hy.setFont(m_gameData->assetsManager.getFont());
	m_hy.setString(L"NGUYỄN HOÀNG HY");
	m_hy.setStyle(sf::Text::Style::Bold);
	m_hy.setCharacterSize(20);
	m_hy.setOrigin(m_hy.getLocalBounds().width / 2, m_hy.getLocalBounds().height / 2);
	m_hy.setPosition(755.f, 320.f);
	m_hy.setFillColor(sf::Color(24, 29, 49, 255));

	// Setup back button
	m_backButton.setFont(m_gameData->assetsManager.getFont());
	m_backButton.setString(L"TRỞ VỀ");
	m_backButton.setStyle(sf::Text::Style::Bold);
	m_backButton.setCharacterSize(20);
	m_backButton.setOrigin(m_backButton.getLocalBounds().width / 2, m_backButton.getLocalBounds().height / 2);
	m_backButton.setPosition(70.f, 450.f);
	m_backButton.setFillColor(sf::Color(24, 29, 49, 255));

	// Setup title
	m_title.setFont(m_gameData->assetsManager.getFont());
	m_title.setString(L"CHUYÊN MỤC XIN DONATE");
	m_title.setStyle(sf::Text::Style::Bold);
	m_title.setCharacterSize(20);
	m_title.setOrigin(m_title.getLocalBounds().width / 2, m_title.getLocalBounds().height / 2);
	m_title.setPosition(450.f, 50.f);
	m_title.setFillColor(sf::Color(24, 29, 49, 255));
}

void AboutScene::handleEvent()
{
	sf::Event event;

	while (m_gameData->window.pollEvent(event))
	{
		if (event.type == sf::Event::EventType::Closed)
		{
			m_gameData->window.close();
		}

		if (event.type == sf::Event::EventType::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Button::Left)
			{
				m_isMouseClicked = true;
			}
		}
	}
}

void AboutScene::update(float delta)
{
	if (isMouseContainText(m_backButton, m_gameData->window))
	{
		m_backButton.setFillColor(sf::Color(157, 92, 13, 255));

		if (m_isMouseClicked)
		{
			m_gameData->sceneManager.removeScene();

			m_isMouseClicked = false;
		}
	}
	else
	{
		m_backButton.setFillColor(sf::Color(24, 29, 49, 255));
	}

	if (isMouseContainText(m_adonis, m_gameData->window))
	{
		m_adonis.setFillColor(sf::Color(157, 92, 13, 255));

		if (m_isMouseClicked)
		{
			openURL("https://www.facebook.com/adonis.harding");

			m_isMouseClicked = false;
		}
	}
	else
	{
		m_adonis.setFillColor(sf::Color(24, 29, 49, 255));
	}

	if (isMouseContainText(m_hy, m_gameData->window))
	{
		m_hy.setFillColor(sf::Color(157, 92, 13, 255));

		if (m_isMouseClicked)
		{
			openURL("https://www.facebook.com/hy.nguyenhoang");

			m_isMouseClicked = false;
		}
	}
	else
	{
		m_hy.setFillColor(sf::Color(24, 29, 49, 255));
	}

	m_isMouseClicked = false;
}

void AboutScene::draw()
{
	m_gameData->window.clear(sf::Color(240, 233, 210, 255));

	m_gameData->window.draw(m_background);
	m_gameData->window.draw(m_backButton);
	m_gameData->window.draw(m_adonis);
	m_gameData->window.draw(m_hy);
	m_gameData->window.draw(m_adonis_qrcode);
	m_gameData->window.draw(m_hy_qrcode);
	m_gameData->window.draw(m_title);

	m_gameData->window.display();
}

void AboutScene::openURL(const std::string& url)
{
#if defined (SFML_SYSTEM_WINDOWS)
	ShellExecute(0, 0, url.c_str(), 0, 0, SW_SHOW);
#elif defined (SFML_SYSTEM_LINUX)
	std::string cmd = std::string("xdg-open ").append(url);
	system(cmd.c_str());
#endif
}