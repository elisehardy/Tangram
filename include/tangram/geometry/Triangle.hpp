#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <MLV/MLV_color.h>

#include <tangram/geometry/Point.hpp>


namespace tangram::geometry {
    
    class Triangle {
        
        private:
            Point16 p1;
            Point16 p2;
            Point16 p3;
        
        public:
            static constexpr int16_t ANGLE_STEP = 3;
            static constexpr int16_t SIDE = 100;
            static const int16_t HYPOTENUSE;
            static const int16_t HEIGHT;
            
            explicit Triangle(const Point16 &offset);
            
            Triangle(Point16 p1, Point16 p2, Point16 p3);
            
            friend std::ostream &operator<<(std::ostream &os, const Triangle &t);
            
            [[nodiscard]] Triangle translate(const Vector16 &v) const;
            
            [[nodiscard]] Triangle translate(int16_t x, int16_t y) const;
            
            [[nodiscard]] Triangle scale(const VectorD &v) const;
            
            [[nodiscard]] Triangle scale(double x, double y) const;
            
            [[nodiscard]] Triangle scale(double factor) const;
            
            [[nodiscard]] Triangle rotate(int16_t n, const PointD &center) const;
            
            [[nodiscard]] bool contains(const Point16 &p) const;
            
            [[nodiscard]] std::vector<Point16> getPoints() const;
            
            void draw(MLV_Color color) const;
    };
}

#endif // TRIANGLE_HPP