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

#include <Scenes/SplashScene.hpp>
#include <Scenes/MenuScene.hpp>

SplashScene::SplashScene(GameData::Ref gameData) :
	m_gameData(gameData),
	m_time(0.f)
{
}

void SplashScene::init()
{
	m_color_background = sf::Color(77, 63, 27, 255);

	m_background.setTexture(m_gameData->assetsManager.getTexture(1));
	m_background.setOrigin(sf::Vector2f(m_gameData->assetsManager.getTexture(1).getSize() / 2u));
	m_background.setPosition(450.f, 300.f);
	m_background.setColor(m_color_background);
}

void SplashScene::handleEvent()
{
	sf::Event event;

	while (m_gameData->window.pollEvent(event))
	{
		if (event.type == sf::Event::EventType::Closed)
		{
			m_gameData->window.close();
		}
	}
}

void SplashScene::update(float delta)
{
	m_time += delta;

	if (m_time > 3.f)
	{
		m_gameData->sceneManager.addScene(Scene::Ref(new MenuScene(m_gameData)));
	}
	else
	{
		m_color_background.a = static_cast<sf::Uint8>(std::sin(m_time * 60 * DEG_TO_RAD) * 255);

		m_background.setColor(m_color_background);
	}
}

void SplashScene::draw()
{
	m_gameData->window.clear(sf::Color(254, 250, 224, 255));

	m_gameData->window.draw(m_background);

	m_gameData->window.display();
}