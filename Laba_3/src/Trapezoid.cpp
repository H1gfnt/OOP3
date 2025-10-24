#include "../include/Trapezoid.h"

double Trapezoid::distance(const Points& A, const Points& B) const {
    return std::sqrt(std::pow(B.getX() - A.getX(), 2) + std::pow(B.getY() - A.getY(), 2));
}

double Trapezoid::crossProduct(const Points& A, const Points& B, const Points& C) const {
    return (B.getX() - A.getX()) * (C.getY() - A.getY()) - 
           (B.getY() - A.getY()) * (C.getX() - A.getX());
}

bool Trapezoid::areParallel(const Points& A, const Points& B, const Points& C, const Points& D) const {
    double ABx = B.getX() - A.getX();
    double ABy = B.getY() - A.getY();
    double CDx = D.getX() - C.getX();
    double CDy = D.getY() - C.getY();
    
    const double epsilon = 1e-9;
    return std::abs(ABx * CDy - ABy * CDx) < epsilon;
}

bool Trapezoid::isValidTrapezoid(const Points& p1, const Points& p2, const Points& p3, const Points& p4) const {
    if (p1 == p2 || p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4 || p3 == p4) {
        return false;
    }
    
    bool bases1 = areParallel(p1, p2, p3, p4);
    bool bases2 = areParallel(p2, p3, p4, p1); 
    
    return bases1 || bases2;
}

Trapezoid::Trapezoid(const Points& p1, const Points& p2, const Points& p3, const Points& p4) {
    if (!isValidTrapezoid(p1, p2, p3, p4)) {
        throw std::invalid_argument("Error: points do not form a valid trapezoid.");
    }

    v_1 = p1; 
    v_2 = p2; 
    v_3 = p3; 
    v_4 = p4;
}

Trapezoid::Trapezoid(const Trapezoid& other) :
    v_1(other.v_1), 
    v_2(other.v_2), 
    v_3(other.v_3), 
    v_4(other.v_4) 
{}

Trapezoid::operator double() const {
    return area();
}

Trapezoid::Trapezoid(Trapezoid&& other) noexcept :
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

Points Trapezoid::geometricalCenter() const {
    double centerX = (v_1.getX() + v_2.getX() + v_3.getX() + v_4.getX()) / 4;
    double centerY = (v_1.getY() + v_2.getY() + v_3.getY() + v_4.getY()) / 4;
    return Points(centerX, centerY);
}

double Trapezoid::area() const {
    double sum1 = v_1.getX() * v_2.getY() + 
                  v_2.getX() * v_3.getY() + 
                  v_3.getX() * v_4.getY() + 
                  v_4.getX() * v_1.getY();
    
    double sum2 = v_1.getY() * v_2.getX() + 
                  v_2.getY() * v_3.getX() + 
                  v_3.getY() * v_4.getX() + 
                  v_4.getY() * v_1.getX();
    
    return std::abs(sum1 - sum2) / 2.0;
}

Figure& Trapezoid::operator=(const Figure& other) {
    if (this == &other) return *this;
    
    const Trapezoid* otherTrapezoid = dynamic_cast<const Trapezoid*>(&other);
    if (!otherTrapezoid) {
        throw std::invalid_argument("Cannot assign non-Trapezoid to Trapezoid");
    }
    
    v_1 = otherTrapezoid->v_1;
    v_2 = otherTrapezoid->v_2;
    v_3 = otherTrapezoid->v_3;
    v_4 = otherTrapezoid->v_4;
    
    return *this;
}

Figure& Trapezoid::operator=(Figure&& other) noexcept {
    if (this == &other) return *this;
    
    Trapezoid* otherTrapezoid = dynamic_cast<Trapezoid*>(&other);
    if (otherTrapezoid) {
        v_1 = std::move(otherTrapezoid->v_1);
        v_2 = std::move(otherTrapezoid->v_2);
        v_3 = std::move(otherTrapezoid->v_3);
        v_4 = std::move(otherTrapezoid->v_4);
    }
    return *this;
}

bool Trapezoid::operator==(const Figure& other) const {
    const Trapezoid* otherTrapezoid = dynamic_cast<const Trapezoid*>(&other);
    if (!otherTrapezoid) return false;
    
    return v_1 == otherTrapezoid->v_1 && 
           v_2 == otherTrapezoid->v_2 && 
           v_3 == otherTrapezoid->v_3 && 
           v_4 == otherTrapezoid->v_4;
}

Trapezoid& Trapezoid::operator=(const Trapezoid& other) {
    if (this == &other) return *this;
    
    v_1 = other.v_1;
    v_2 = other.v_2;
    v_3 = other.v_3;
    v_4 = other.v_4;
    
    return *this;
}

Trapezoid& Trapezoid::operator=(Trapezoid&& other) noexcept {
    if (this == &other) return *this;
    
    v_1 = std::move(other.v_1);
    v_2 = std::move(other.v_2);
    v_3 = std::move(other.v_3);
    v_4 = std::move(other.v_4);
    
    return *this;
}

bool Trapezoid::operator==(const Trapezoid& other) const {
    if (this == &other) return true;
    
    return v_1 == other.v_1 && 
           v_2 == other.v_2 && 
           v_3 == other.v_3 && 
           v_4 == other.v_4;
}

Trapezoid* Trapezoid::clone() const {
    return new Trapezoid(*this);
}

std::ostream &operator<<(std::ostream &stream, const Trapezoid &trapezoid) {
    stream << "Trapezoid vertices: ";
    stream << "(" << trapezoid.v_1.getX() << ", " << trapezoid.v_1.getY() << ") ";
    stream << "(" << trapezoid.v_2.getX() << ", " << trapezoid.v_2.getY() << ") ";
    stream << "(" << trapezoid.v_3.getX() << ", " << trapezoid.v_3.getY() << ") ";
    stream << "(" << trapezoid.v_4.getX() << ", " << trapezoid.v_4.getY() << ")";
    return stream;
}

std::istream &operator>>(std::istream &stream, Trapezoid &trapezoid) {
    double x1, y1, x2, y2, x3, y3, x4, y4;
    
    std::cout << "Enter four vertices of the trapezoid (x1 y1 x2 y2 x3 y3 x4 y4): ";
    stream >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    Points p1(x1, y1);
    Points p2(x2, y2);
    Points p3(x3, y3);
    Points p4(x4, y4);
    
    trapezoid = Trapezoid(p1, p2, p3, p4);
    
    return stream;
}
