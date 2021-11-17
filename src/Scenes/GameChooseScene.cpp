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

#include <Scenes/GameChooseScene.hpp>

GameChooseScene::GameChooseScene(GameData::Ref gameData) :
	m_gameData(gameData)
{
}

void GameChooseScene::init()
{
	m_title.setFont(m_gameData->assetsManager.getFont());
	m_title.setString(L"XIN MỜI CHỌN CHẾ ĐỘ CHƠI");
	m_title.setStyle(sf::Text::Style::Bold);
	m_title.setCharacterSize(30);
	m_title.setOrigin(m_title.getLocalBounds().width / 2, m_title.getLocalBounds().height / 2);
	m_title.setPosition(450.f, 50.f);
	m_title.setFillColor(sf::Color(24, 29, 49, 255));
}

void GameChooseScene::handleEvent()
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

void GameChooseScene::update(float delta)
{
}

void GameChooseScene::draw()
{
	m_gameData->window.clear(sf::Color(240, 233, 210, 255));

	m_gameData->window.draw(m_title);

	m_gameData->window.display();
}