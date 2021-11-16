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

#include <Scenes/MenuScene.hpp>
#include <Scenes/AboutScene.hpp>
#include <Utils/CheckInput.hpp>

MenuScene::MenuScene(GameData::Ref gameData) :
	m_gameData(gameData),
	m_isMouseClicked(false)
{
}

void MenuScene::init()
{
	// Setup for title
	m_title.setTexture(m_gameData->assetsManager.getTexture(2));
	m_title.setOrigin(sf::Vector2f(m_gameData->assetsManager.getTexture(2).getSize() / 2u));
	m_title.setPosition(450.f, 100.f);
	m_title.setColor(sf::Color(24, 29, 49, 255));

	// Setup for play button
	m_playButton.setFont(m_gameData->assetsManager.getFont());
	m_playButton.setString(L"VÀO CHƠI");
	m_playButton.setStyle(sf::Text::Style::Bold);
	m_playButton.setOrigin(m_playButton.getLocalBounds().width / 2, m_playButton.getLocalBounds().height / 2);
	m_playButton.setPosition(450.f, 220.f);
	m_playButton.setFillColor(sf::Color(24, 29, 49, 255));

	m_aboutButton.setFont(m_gameData->assetsManager.getFont());
	m_aboutButton.setString(L"VỀ CHÚNG TÔI");
	m_aboutButton.setStyle(sf::Text::Style::Bold);
	m_aboutButton.setOrigin(m_aboutButton.getLocalBounds().width / 2, m_aboutButton.getLocalBounds().height / 2);
	m_aboutButton.setPosition(450.f, 300.f);
	m_aboutButton.setFillColor(sf::Color(24, 29, 49, 255));

	m_exitButton.setFont(m_gameData->assetsManager.getFont());
	m_exitButton.setString(L"THOÁT");
	m_exitButton.setStyle(sf::Text::Style::Bold);
	m_exitButton.setOrigin(m_exitButton.getLocalBounds().width / 2, m_exitButton.getLocalBounds().height / 2);
	m_exitButton.setPosition(450.f, 380.f);
	m_exitButton.setFillColor(sf::Color(24, 29, 49, 255));
}

void MenuScene::handleEvent()
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

void MenuScene::update(float delta)
{
	if (isMouseContainText(m_playButton, m_gameData->window))
	{
		m_playButton.setFillColor(sf::Color(157, 92, 13, 255));

		if (m_isMouseClicked)
		{
			m_isMouseClicked = false;
		}
	}
	else
	{
		m_playButton.setFillColor(sf::Color(24, 29, 49, 255));
	}

	if (isMouseContainText(m_aboutButton, m_gameData->window))
	{
		m_aboutButton.setFillColor(sf::Color(157, 92, 13, 255));

		if (m_isMouseClicked)
		{
			m_gameData->sceneManager.addScene(Scene::Ref(new AboutScene(m_gameData)), false);

			m_isMouseClicked = false;
		}
	}
	else
	{
		m_aboutButton.setFillColor(sf::Color(24, 29, 49, 255));
	}

	if (isMouseContainText(m_exitButton, m_gameData->window))
	{
		m_exitButton.setFillColor(sf::Color(157, 92, 13, 255));

		if (m_isMouseClicked)
		{
			m_gameData->window.close();

			m_isMouseClicked = false;
		}
	}
	else
	{
		m_exitButton.setFillColor(sf::Color(24, 29, 49, 255));
	}

	m_isMouseClicked = false;
}

void MenuScene::draw()
{
	m_gameData->window.clear(sf::Color(240, 233, 210, 255));

	m_gameData->window.draw(m_title);

	m_gameData->window.draw(m_playButton);
	m_gameData->window.draw(m_aboutButton);
	m_gameData->window.draw(m_exitButton);

	m_gameData->window.display();
}