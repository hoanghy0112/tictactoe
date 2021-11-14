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

#include <Core/AssetsManager.hpp>

sf::Texture & AssetsManager::getTexture(int id)
{
	return m_textures[id];
}

sf::Font& AssetsManager::getFont()
{
	return m_font;
}

void AssetsManager::init()
{
	tinyxml2::XMLDocument document;

	document.LoadFile("assets/assets.xml");

	tinyxml2::XMLElement* textures = document.FirstChildElement()->FirstChildElement();
	tinyxml2::XMLElement* soundBuffers = textures->NextSiblingElement();

	// Load textures
	for (auto element = textures->FirstChildElement(); element != nullptr; element = element->NextSiblingElement())
	{
		int id = std::atoi(element->Attribute("id"));
		std::string path = element->GetText();

		sf::Texture texture;
		texture.loadFromFile(path);

		m_textures[id] = texture;
	}

	// Load sound buffers
	for (auto element = soundBuffers->FirstChildElement(); element != nullptr; element = element->NextSiblingElement())
	{
		int id = std::atoi(element->Attribute("id"));
		std::string path = element->GetText();

		sf::SoundBuffer soundBuffer;
		soundBuffer.loadFromFile(path);

		m_soundBuffer[id] = soundBuffer;
	}

	// Load font

}