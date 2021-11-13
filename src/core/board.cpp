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

#include <src/core/board.hpp>

Board::Board(Type size) :
	m_gridX(40),
	m_gridY(40),
	m_size_of_cell(0)
{
	// Create the board
	m_board = std::make_shared<BoardData>();

	switch (size)
	{
	case Type::Three:
		m_board->size = 3;
		m_size_of_cell = 140;
		break;

	case Type::Five:
		m_board->size = 5;
		m_size_of_cell = 84;
		break;

	case Type::Seven:
		m_board->size = 7;
		m_size_of_cell = 60;
		break;
	}

	// Allocate pointer
	m_board->data = new Point* [m_board->size];
	for (int i = 0; i < m_board->size; i++)
	{
		m_board->data[i] = new Point[m_board->size];
	}

	// Set value for board
	for (int i = 0; i < m_board->size; i++)
	{
		for (int j = 0; j < m_board->size; j++)
		{
			m_board->data[i][j].x = i;
			m_board->data[i][j].x = j;
			m_board->data[i][j].type = PointType::None;
		}
	}


}

Board::~Board()
{
}

void Board::update()
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		float deltaX = GetMousePosition().x - m_gridX;
		float deltaY = GetMousePosition().y - m_gridY;

		if ((deltaX >= 0 && deltaX <= m_board->size * m_size_of_cell) && (deltaY >= 0 && deltaY <= m_board->size * m_size_of_cell))
		{
			int x = static_cast<int>(deltaX) / m_size_of_cell;
			int y = static_cast<int>(deltaY) / m_size_of_cell;

			static bool check = true;

			if (m_board->data[x][y].type == PointType::None)
			{
				if (check)
				{
					m_board->data[x][y].type = PointType::Player_1;
					check = !check;
				}
				else
				{
					m_board->data[x][y].type = PointType::Player_2;
					check = !check;
				}
			}
		}
	}
}

void Board::draw()
{
	// Draw horizontal line
	for (int i = 0; i <= m_board->size; i++)
	{
		DrawLine(m_gridX, i * m_size_of_cell + m_gridY, m_board->size * m_size_of_cell + m_gridX, i * m_size_of_cell + m_gridY, GREEN);
	}

	// Draw vertical line
	for (int i = 0; i <= m_board->size; i++)
	{
		DrawLine(i * m_size_of_cell + m_gridX, m_gridY, i * m_size_of_cell + m_gridX, m_board->size * m_size_of_cell + m_gridY, GREEN);
	}

	// Draw chess pieces
	for (int i = 0; i < m_board->size; i++)
	{
		for (int j = 0; j < m_board->size; j++)
		{
			switch (m_board->data[i][j].type)
			{
			case PointType::Player_1:
				DrawText("o", i * m_size_of_cell + m_gridX, j * m_size_of_cell + m_gridY, 60, RED);
				break;
			case PointType::Player_2:
				DrawText("x", i * m_size_of_cell + m_gridX, j * m_size_of_cell + m_gridY, 60, YELLOW);
				break;
			}
		}
	}
}