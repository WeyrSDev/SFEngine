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
#include <sfcss/ui/widgets/button_base.h>

////////////////////////////////////////////////////////////
// Dependency Headers
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Standard Library Headers
////////////////////////////////////////////////////////////

namespace css
{

  button_base::button_base(css_widget::rptr parent)
    : clickable_widget(parent)
  {
    left_clicked.connect(std::bind(&button_base::on_left_clicked, this, std::placeholders::_1), m_id);
    right_clicked.connect(std::bind(&button_base::on_right_clicked, this, std::placeholders::_1), m_id);
    hover_on.connect(std::bind(&button_base::on_hovered, this, std::placeholders::_1), m_id);
    hover_off.connect(std::bind(&button_base::on_exited, this, std::placeholders::_1), m_id);
  }

  css::button_base::sptr button_base::create(css_widget::rptr parent)
  {
    return nullptr;
  }

  void button_base::update()
  {

  }

  void button_base::on_left_clicked(const Vec2 &where)
  {

  }

  void button_base::on_right_clicked(const Vec2 &where)
  {

  }

  void button_base::on_hovered(const Vec2 &where)
  {

  }

  void button_base::on_exited(const Vec2 &where)
  {

  }

}
