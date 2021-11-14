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

static sf::Texture t;
static sf::Sprite s;
static sf::Clock c;

SplashScene::SplashScene(GameData::Ref gameData) :
	m_gameData(gameData)
{
	t.loadFromFile("assets/textures/splash_background.png");
	s.setTexture(t);
	s.setColor(sf::Color::Red);
}

void SplashScene::init()
{
	c.restart();
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
	float tt = c.getElapsedTime().asSeconds() * 90;

	if (tt <= 180)
	s.setColor(sf::Color(std::sin(tt * 0.01745) * 255, std::sin(tt * 0.01745) * 255, std::sin(tt * 0.01745) * 255, std::sin(tt * 0.01745) * 255));
}

void SplashScene::draw()
{
	m_gameData->window.clear();

	m_gameData->window.draw(s);

	m_gameData->window.display();
}