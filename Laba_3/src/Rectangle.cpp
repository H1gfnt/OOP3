#include "../include/Rectangle.h"

double Rectangle::distance(const Points& A, const Points& B) const {
    return std::sqrt(std::pow(B.getX() - A.getX(), 2) + std::pow(B.getY() - A.getY(), 2));
}

double Rectangle::dotProduct(const Points& A, const Points& B, const Points& C) const {
    double ABx = B.getX() - A.getX();
    double ABy = B.getY() - A.getY();
    double BCx = C.getX() - B.getX();
    double BCy = C.getY() - B.getY();
    return ABx * BCx + ABy * BCy;
}

bool Rectangle::arePerpendicular(const Points& A, const Points& B, const Points& C) const {
    const double epsilon = 1e-9;
    return std::abs(dotProduct(A, B, C)) < epsilon;
}

bool Rectangle::isValidRectangle(const Points& p1, const Points& p2, const Points& p3, const Points& p4) const {
    if (p1 == p2 || p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4 || p3 == p4) {
        return false;
    }
    
    bool angle1 = arePerpendicular(p1, p2, p3);
    bool angle2 = arePerpendicular(p2, p3, p4);
    bool angle3 = arePerpendicular(p3, p4, p1);
    
    return angle1 && angle2 && angle3;
}

Rectangle::Rectangle(const Points& p1, const Points& p2, const Points& p3, const Points& p4) {
    if (!isValidRectangle(p1, p2, p3, p4)) {
        throw std::invalid_argument("Error: points do not form a valid rectangle.");
    }

    v_1 = p1; 
    v_2 = p2; 
    v_3 = p3; 
    v_4 = p4;
}

Rectangle::Rectangle(const Rectangle& other) :
    v_1(other.v_1), 
    v_2(other.v_2), 
    v_3(other.v_3), 
    v_4(other.v_4) 
{}

Rectangle::operator double() const {
    return area();
}

Rectangle::Rectangle(Rectangle&& other) noexcept :
    v_1(std::move(other.v_1)),
    v_2(std::move(other.v_2)),
    v_3(std::move(other.v_3)),
    v_4(std::move(other.v_4))
{
    other.v_1 = Points();
    other.v_2 = Points();
    other.v_3 = Points();
    other.v_4 = Points();
}

Points Rectangle::geometricalCenter() const {
    double centerX = (v_1.getX() + v_2.getX() + v_3.getX() + v_4.getX()) / 4;
    double centerY = (v_1.getY() + v_2.getY() + v_3.getY() + v_4.getY()) / 4;
    return Points(centerX, centerY);
}

double Rectangle::area() const {
    double width = distance(v_1, v_2);
    double height = distance(v_2, v_3);
    return width * height;
}

Figure& Rectangle::operator=(const Figure& other) {
    if (this == &other) return *this;
    
    const Rectangle* otherRectangle = dynamic_cast<const Rectangle*>(&other);
    if (!otherRectangle) {
        throw std::invalid_argument("Cannot assign non-Rectangle to Rectangle");
    }
    
    v_1 = otherRectangle->v_1;
    v_2 = otherRectangle->v_2;
    v_3 = otherRectangle->v_3;
    v_4 = otherRectangle->v_4;
    
    return *this;
}

Figure& Rectangle::operator=(Figure&& other) noexcept {
    if (this == &other) return *this;
    
    Rectangle* otherRectangle = dynamic_cast<Rectangle*>(&other);
    if (otherRectangle) {
        v_1 = std::move(otherRectangle->v_1);
        v_2 = std::move(otherRectangle->v_2);
        v_3 = std::move(otherRectangle->v_3);
        v_4 = std::move(otherRectangle->v_4);
    }
    return *this;
}

bool Rectangle::operator==(const Figure& other) const {
    const Rectangle* otherRectangle = dynamic_cast<const Rectangle*>(&other);
    if (!otherRectangle) return false;
    
    return v_1 == otherRectangle->v_1 && 
           v_2 == otherRectangle->v_2 && 
           v_3 == otherRectangle->v_3 && 
           v_4 == otherRectangle->v_4;
}

Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this == &other) return *this;
    
    v_1 = other.v_1;
    v_2 = other.v_2;
    v_3 = other.v_3;
    v_4 = other.v_4;
    
    return *this;
}

Rectangle& Rectangle::operator=(Rectangle&& other) noexcept {
    if (this == &other) return *this;
    
    v_1 = std::move(other.v_1);
    v_2 = std::move(other.v_2);
    v_3 = std::move(other.v_3);
    v_4 = std::move(other.v_4);
    
    return *this;
}

bool Rectangle::operator==(const Rectangle& other) const {
    if (this == &other) return true;
    
    return v_1 == other.v_1 && 
           v_2 == other.v_2 && 
           v_3 == other.v_3 && 
           v_4 == other.v_4;
}

Rectangle* Rectangle::clone() const {
    return new Rectangle(*this);
}

std::ostream &operator<<(std::ostream &stream, const Rectangle &rectangle) {
    stream << "Rectangle vertices: ";
    stream << "(" << rectangle.v_1.getX() << ", " << rectangle.v_1.getY() << ") ";
    stream << "(" << rectangle.v_2.getX() << ", " << rectangle.v_2.getY() << ") ";
    stream << "(" << rectangle.v_3.getX() << ", " << rectangle.v_3.getY() << ") ";
    stream << "(" << rectangle.v_4.getX() << ", " << rectangle.v_4.getY() << ")";
    return stream;
}

std::istream &operator>>(std::istream &stream, Rectangle &rectangle) {
    double x1, y1, x2, y2, x3, y3, x4, y4;
    
    std::cout << "Enter four vertices of the rectangle (x1 y1 x2 y2 x3 y3 x4 y4): ";
    stream >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    Points p1(x1, y1);
    Points p2(x2, y2);
    Points p3(x3, y3);
    Points p4(x4, y4);
    
    rectangle = Rectangle(p1, p2, p3, p4);
    
    return stream;
}

