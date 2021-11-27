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
#include <Core/SceneManager.hpp>
#include <Core/AssetsManager.hpp>

struct GameData
{
	using Ref = std::shared_ptr<GameData>;

	SceneManager		sceneManager;
	AssetsManager		assetsManager;

	sf::RenderWindow	window;
};

/*
** Type of point
*/
enum class PointType
{
	None = 0,
	Player_1,
	Player_2,
};

/*
** Point in a board
*/
struct Point
{
	int			x;
	int			y;
	PointType	type;
};

/*
** Struct of board
*/
struct BoardData
{
	int			size;
	Point**		data;
};