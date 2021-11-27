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

#include <Application.hpp>
#include <Scenes/SplashScene.hpp>
#include <Cursor.hpp>

static Application::Ref s_application_instance = nullptr;
static sf::Cursor s_cursor;

Application::Application()
{
	init();
}

Application::~Application()
{
	destroy();
}

Application::Ref& Application::getInstance()
{
	if (!s_application_instance)
	{
		s_application_instance = std::make_unique<Application>();
	}

	return s_application_instance;
}

void Application::run()
{
	sf::Clock clock;
	sf::Time elapsedTime = sf::Time::Zero;

	while (m_gameData->window.isOpen())
	{
		elapsedTime = clock.restart();

		m_gameData->sceneManager.processSceneChange();

		m_gameData->sceneManager.getCurrentScene()->handleEvent();

		m_gameData->sceneManager.getCurrentScene()->update(elapsedTime.asSeconds());

		m_gameData->sceneManager.getCurrentScene()->draw();
	}
}

void Application::init()
{
	m_gameData = std::make_shared<GameData>();

	m_gameData->window.create(sf::VideoMode(900, 600), "Tic Tac Toe", sf::Style::Titlebar);
	m_gameData->window.setFramerateLimit(60);

	s_cursor.loadFromPixels(cursor.pixel_data, sf::Vector2u(cursor.width, cursor.height), sf::Vector2u(0u, 0u));
	m_gameData->window.setMouseCursor(s_cursor);

	m_gameData->assetsManager.init();

	m_gameData->sceneManager.addScene(Scene::Ref(new SplashScene(this->m_gameData)));

	m_gameData->background_music.openFromFile("assets/audios/background_music.ogg");
	m_gameData->background_music.setLoop(true);
	m_gameData->background_music.play();
}

void Application::destroy()
{
	m_gameData.reset();
}