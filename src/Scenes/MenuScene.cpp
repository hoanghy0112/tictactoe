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

MenuScene::MenuScene(GameData::Ref gameData) :
	m_gameData(gameData)
{
}

MenuScene::~MenuScene()
{
	if (m_play_button != nullptr)
	{
		delete m_play_button;

		m_play_button = nullptr;
	}

	if (m_about_button != nullptr)
	{
		delete m_about_button;

		m_about_button = nullptr;
	}

	if (m_exit_button != nullptr)
	{
		delete m_exit_button;

		m_exit_button = nullptr;
	}
}

void MenuScene::init()
{
	m_background.setTexture(m_gameData->assetsManager.getTexture(2));
	m_background.setOrigin(sf::Vector2f(m_gameData->assetsManager.getTexture(2).getSize() / 2u));
	m_background.setPosition(800.f, 400.f);

	m_title.setTexture(m_gameData->assetsManager.getTexture(3));
	m_title.setOrigin(sf::Vector2f(m_gameData->assetsManager.getTexture(3).getSize() / 2u));
	m_title.setPosition(450.f, 160.f);

	m_play_button = new ButtonImage(m_gameData->assetsManager.getTexture(4), m_gameData->assetsManager.getTexture(5));
	m_play_button->setPosition(450.f, 280.f);

	m_about_button = new ButtonImage(m_gameData->assetsManager.getTexture(6), m_gameData->assetsManager.getTexture(7));
	m_about_button->setPosition(450.f, 360.f);

	m_exit_button = new ButtonImage(m_gameData->assetsManager.getTexture(8), m_gameData->assetsManager.getTexture(9));
	m_exit_button->setPosition(450.f, 440.f);
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

		m_play_button->handleEvent(event);
		m_about_button->handleEvent(event);
		m_exit_button->handleEvent(event);
	}
}

void MenuScene::update(float delta)
{
	if (m_play_button->isButtonPressed(m_gameData->window))
	{
	}

	if (m_about_button->isButtonPressed(m_gameData->window))
	{
	}

	if (m_exit_button->isButtonPressed(m_gameData->window))
	{
		m_gameData->window.close();
	}
}

void MenuScene::draw()
{
	m_gameData->window.clear(sf::Color(254, 250, 224, 255));

	m_gameData->window.draw(m_background);
	m_gameData->window.draw(m_title);

	m_play_button->draw(m_gameData->window);
	m_about_button->draw(m_gameData->window);
	m_exit_button->draw(m_gameData->window);

	m_gameData->window.display();
}