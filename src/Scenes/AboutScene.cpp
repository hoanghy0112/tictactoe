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

#if defined (SFML_SYSTEM_WINDOWS)
#include <Windows.h>
#endif

AboutScene::AboutScene(GameData::Ref gameData) :
	m_gameData(gameData)
{
}

AboutScene::~AboutScene()
{
	if (m_back_button != nullptr)
	{
		delete m_back_button;

		m_back_button = nullptr;
	}

	if (m_adonis_github != nullptr)
	{
		delete m_adonis_github;

		m_adonis_github = nullptr;
	}

	if (m_hy_github != nullptr)
	{
		delete m_hy_github;

		m_hy_github = nullptr;
	}
}

void AboutScene::init()
{
	m_background.setTexture(m_gameData->assetsManager.getTexture(10));

	m_adonis.setTexture(m_gameData->assetsManager.getTexture(11));
	m_adonis.setOrigin(sf::Vector2f(m_gameData->assetsManager.getTexture(11).getSize() / 2u));
	m_adonis.setPosition(450.f, 200.f);

	m_hy.setTexture(m_gameData->assetsManager.getTexture(12));
	m_hy.setOrigin(sf::Vector2f(m_gameData->assetsManager.getTexture(12).getSize() / 2u));
	m_hy.setPosition(450.f, 400.f);

	m_back_button = new ButtonImage(m_gameData->assetsManager.getTexture(13), m_gameData->assetsManager.getTexture(14));
	m_back_button->setPosition(80.f, 40.f);

	m_adonis_github = new ButtonImage(m_gameData->assetsManager.getTexture(15), m_gameData->assetsManager.getTexture(16));
	m_adonis_github->setPosition(565.f, 225.f);

	m_hy_github = new ButtonImage(m_gameData->assetsManager.getTexture(17), m_gameData->assetsManager.getTexture(18));
	m_hy_github->setPosition(380.f, 420.f);
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

		m_back_button->handleEvent(event);
		m_adonis_github->handleEvent(event);
		m_hy_github->handleEvent(event);
	}
}

void AboutScene::update(float delta)
{
	if (m_back_button->isButtonPressed(m_gameData->window))
	{
		m_gameData->sceneManager.removeScene();
	}

	if (m_adonis_github->isButtonPressed(m_gameData->window))
	{
		openURL("https://github.com/hardingadonis");
	}

	if (m_hy_github->isButtonPressed(m_gameData->window))
	{
		openURL("https://github.com/hoanghy0112");
	}
}

void AboutScene::draw()
{
	m_gameData->window.clear(sf::Color(254, 250, 224, 255));

	m_gameData->window.draw(m_background);
	m_gameData->window.draw(m_adonis);
	m_gameData->window.draw(m_hy);

	m_back_button->draw(m_gameData->window);
	m_adonis_github->draw(m_gameData->window);
	m_hy_github->draw(m_gameData->window);

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