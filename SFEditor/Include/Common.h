#ifndef SFEDITOR_COMMON_H
#define SFEDITOR_COMMON_H

////////////////////////////////////////////////////////////
//
// MIT License
//
// Copyright(c) 2017 Kurt Slagle - kurt_slagle@yahoo.com
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
// The origin of this software must not be misrepresented; you must not claim
// that you wrote the original software.If you use this software in a product,
// an acknowledgment of the software used is required.
//
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Internal Headers
////////////////////////////////////////////////////////////
#include <Include/UI/Globals.h>
//#include <Include/UI/Spacing.h>
#include <Include/Events/UserEvent.h>

#include <UI/Theming/Color.h>

////////////////////////////////////////////////////////////
// Dependency Headers
////////////////////////////////////////////////////////////
#include <SFML\Graphics.hpp>

////////////////////////////////////////////////////////////
// Standard Library Headers
////////////////////////////////////////////////////////////
#include <memory>
#include <vector>
#include <map>

#define to_float(x) (static_cast<float>(x))

using Vec2i = sf::Vector2i;
using Vec2f = sf::Vector2f;
using IntRect = sf::IntRect;
using FloatRect = sf::FloatRect;
using RenderTarget = sf::RenderTarget;

template<typename T_> using SharedPtr = std::shared_ptr<T_>;
template<typename T_> using UniquePtr = std::unique_ptr<T_>;
template<typename T_> using Vector = std::vector<T_>;

template<typename T_, typename U_> using Map  = std::map<T_, U_>;
template<typename T_, typename U_> using Pair = std::pair<T_, U_>;

#endif // SFEDITOR_COMMON_H