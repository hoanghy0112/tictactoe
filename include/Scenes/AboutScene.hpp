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

#pragma once

#include <Config.hpp>
#include <Types.hpp>
#include <Scenes/Scene.hpp>
#include <Core/ButtonImage.hpp>

class AboutScene : public Scene
{
public:
	AboutScene(GameData::Ref gameData);
	~AboutScene();

	void init() override;

	void handleEvent() override;
	void update(float delta) override;
	void draw() override;

private:
	void openURL(const std::string& url);

private:
	GameData::Ref	m_gameData;

	sf::Sprite		m_background;
	sf::Sprite		m_adonis;
	sf::Sprite		m_hy;

	ButtonImage*	m_back_button;
	ButtonImage*	m_adonis_github;
	ButtonImage*	m_hy_github;
};