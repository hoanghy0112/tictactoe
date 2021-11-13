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

#include <config.hpp>
#include <src/core/types.hpp>

class Board
{
public:
	/*
	** Pointer of class Board
	*/
	using Ptr = std::unique_ptr<Board>;

	enum class Type
	{
		Three = 0,		// 3x3 board
		Five,			// 5x5 board
		Seven			// 7x7 board
	};

private:
	BoardData::SharePtr		m_board;

	int						m_gridX;
	int						m_gridY;
	int						m_size_of_cell;



public:
	Board(Type size);
	~Board();

	void update();

	// Draw the board on the screen
	void draw();
};