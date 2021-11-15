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

AboutScene::AboutScene(GameData::Ref gameData) :
	m_gameData(gameData)
{
}

void AboutScene::init()
{
	// Setup for background
	m_background.setTexture(m_gameData->assetsManager.getTexture(3));
	m_background.setOrigin(sf::Vector2f(m_gameData->assetsManager.getTexture(3).getSize() / 2u));
	m_background.setPosition(450.f, 180.f);
	m_background.setColor(sf::Color(24, 29, 49, 255));

	m_adonis.setFont(m_gameData->assetsManager.getFont());
	m_adonis.setString("HARDING ADONIS");
	m_adonis.setStyle(sf::Text::Style::Bold);
	m_adonis.setCharacterSize(20);
	m_adonis.setOrigin(m_adonis.getLocalBounds().width / 2, m_adonis.getLocalBounds().height / 2);
	m_adonis.setPosition(300.f, 380.f);
	m_adonis.setFillColor(sf::Color(24, 29, 49, 255));

	m_hy.setFont(m_gameData->assetsManager.getFont());
	m_hy.setString(L"NGUYỄN HOÀNG HY");
	m_hy.setStyle(sf::Text::Style::Bold);
	m_hy.setCharacterSize(20);
	m_hy.setOrigin(m_hy.getLocalBounds().width / 2, m_hy.getLocalBounds().height / 2);
	m_hy.setPosition(600.f, 380.f);
	m_hy.setFillColor(sf::Color(24, 29, 49, 255));

	// Setup back button
	m_backButton.setFont(m_gameData->assetsManager.getFont());
	m_backButton.setString(L"TRỞ VỀ");
	m_backButton.setStyle(sf::Text::Style::Bold);
	m_backButton.setCharacterSize(20);
	m_backButton.setOrigin(m_backButton.getLocalBounds().width / 2, m_backButton.getLocalBounds().height / 2);
	m_backButton.setPosition(70.f, 450.f);
	m_backButton.setFillColor(sf::Color(24, 29, 49, 255));
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
}

void AboutScene::draw()
{
	m_gameData->window.clear(sf::Color(240, 233, 210, 255));

	m_gameData->window.draw(m_background);
	m_gameData->window.draw(m_backButton);
	m_gameData->window.draw(m_adonis);
	m_gameData->window.draw(m_hy);

	m_gameData->window.display();
}