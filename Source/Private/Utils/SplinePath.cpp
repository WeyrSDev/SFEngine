////////////////////////////////////////////////////////////
//
// MIT License
//
// Copyright(c) 2017 Kurt Slagle - kurt_slagle@yahoo.com
// Copyright(c) 2017 Austin Bailey
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

/************************************************************************/
/*                         Internal  Headers                            */
/************************************************************************/
#include "Utils\SplinePath.h"
#include "Globals.h"

/************************************************************************/
/*                       Dependency  Headers                            */
/************************************************************************/

/************************************************************************/
/*                     Standard  Library  Headers                       */
/************************************************************************/

/************************************************************************/
/*                         SplinePath                                   */
/************************************************************************/
/*                                                                      */
/*                                                                      */
/************************************************************************/

/************************************************************************/
/* Last Edit: Kurt Slagle - 2017/04/27                                  */
/************************************************************************/

namespace SFEngine
{

  SplinePath::SplinePath(UINT32 PathStyle)
  {
    m_Style = PathStyle;
    //m_Spline.setHandlesVisible(true);
    //m_Spline.setPrimitiveType(sf::Points);
  }

  void SplinePath::MakeCirclularPath(const SVector2F & Center, SFLOAT Radius, UINT32 NumPts)
  {
    assert(NumPts != 0);

    SFLOAT Theta = 0.f;
    SFLOAT dTheta = 2 * ____PI / NumPts;

    SVector2F Point;
    SFLOAT s = 0.f; SFLOAT c = 0.f;
    for (UINT32 i = 0; i < NumPts; ++i) {
      s = ::sin(Theta);
      c = ::cos(Theta);
      Theta += dTheta;

      Point = Center + Radius * SVector2F(c, s);
      m_Spline.addVertex(Point);
    }

    //Connect the last/first point
    Point = Center + Radius * SVector2F(1, 0);
    m_Spline.addVertex(Point);

    if (m_Style & SplinePath::Cubic)
      m_Spline.setBezierInterpolation(true);

    if (m_Style & SplinePath::Smooth)
      m_Spline.smoothHandles();

    m_Spline.update();
  }

  void SplinePath::SetThickness(SFLOAT Thickness)
  {
    m_Spline.setThickness(Thickness);
  }

  UINT32 SplinePath::GetNumInterpolantPoints() const
  {
    return m_Spline.getInterpolationSteps();
  }

  void SplinePath::AddVertexAtEnd(const SVector2F & Position)
  {
    m_Spline.addVertex(Position);
  }

  void SplinePath::AddVertices(const STDVector<SVector2F>& Vertices)
  {
    m_Spline.addVertices(Vertices);
  }

  void SplinePath::MoveVertex(UINT32 Index, const SVector2F & NewPosition)
  {
    if (Index < m_Spline.getVertexCount()) {
      m_Spline[Index].position = NewPosition;
      m_Spline.update();
    }
  }

  void SplinePath::MakeSmooth()
  {
    m_Spline.smoothHandles();
  }

  void SplinePath::SetInterpolationSteps(UINT32 NumSteps)
  {
    m_Spline.setBezierInterpolation(true);
    m_Spline.setInterpolationSteps(NumSteps);
    m_Spline.update();
  }

  void SplinePath::RemoveVertex(UINT32 Index)
  {
    if (Index < m_Spline.getVertexCount()) {
      m_Spline.removeVertex(Index);
    }
  }

  void SplinePath::SetPrimitiveType(sf::PrimitiveType PType)
  {
    m_SplinePrimitiveType = PType;
    m_Spline.setPrimitiveType(PType);
  }

  void SplinePath::SetColor(sf::Color Color)
  {
    m_Spline.setColor(Color);
  }

  SVector2F SplinePath::operator[](const UINT32 & Index)
  {
    if (Index < m_Spline.getVertexCount()) {
      return m_Spline[Index].position;
    }

    return SVector2F();
  }

  void SplinePath::Update()
  {
    m_Spline.update();
  }

  void SplinePath::Render(SharedRTexture Target)
  {
    Target->draw(m_Spline);
  }

  SVector2F SplinePath::GetNextPathPoint()
  {
    SVector2F pos;

    if (m_CurrentPathPoint < m_Spline.getInterpolatedVertexCount()) {
      pos = m_Spline.getInterpolatedVertex(m_CurrentPathPoint);
      m_CurrentPathPoint++;
    }
    else if (m_Spline.getInterpolatedVertexCount() > 0) {
      pos = m_Spline.getInterpolatedVertex(0);
      m_CurrentPathPoint = 0;
      m_CurrentPathPoint++;
    }

    return pos;

  }

} // namespace SFEngine
