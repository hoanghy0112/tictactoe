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

#include <Core/SceneManager.hpp>

SceneManager::SceneManager() :
	m_isRemoving(false),
	m_isAdding(false),
	m_isReplacing(false)
{
}

void SceneManager::addScene(Scene::Ref newScene, bool isReplacing)
{
	m_isAdding = true;
	m_isReplacing = isReplacing;

	m_newScene = std::move(newScene);
}

void SceneManager::removeScene()
{
	m_isRemoving = true;
}

void SceneManager::processSceneChange()
{
	if (m_isRemoving && !m_scenes.empty())
	{
		m_scenes.pop();

		if (!m_scenes.empty())
		{
			m_scenes.top()->resume();
		}

		m_isRemoving = false;
	}

	if (m_isAdding)
	{
		if (!m_scenes.empty())
		{
			if (m_isReplacing)
			{
				m_scenes.pop();
			}
			else
			{
				m_scenes.top()->pause();
			}
		}

		m_scenes.push(std::move(m_newScene));
		m_scenes.top()->init();

		m_isAdding = false;
	}
}

Scene::Ref& SceneManager::getCurrentScene()
{
	return m_scenes.top();
}