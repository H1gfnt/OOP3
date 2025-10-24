#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "Figure.h"
#include <cmath>

class Trapezoid : public Figure {
    friend std::ostream &operator<<(std::ostream &stream, const Trapezoid &trapezoid);
    friend std::istream &operator>>(std::istream &stream, Trapezoid &trapezoid);
private:
    Points v_1, v_2, v_3, v_4;
    
    bool isValidTrapezoid(const Points& p1, const Points& p2, const Points& p3, const Points& p4) const;
    double distance(const Points& A, const Points& B) const;
    bool areParallel(const Points& A, const Points& B, const Points& C, const Points& D) const;
    double crossProduct(const Points& A, const Points& B, const Points& C) const;
    
public:
    Trapezoid() = default;
    Trapezoid(const Points& p1, const Points& p2, const Points& p3, const Points& p4);
    Trapezoid(const Trapezoid& other);
    Trapezoid(Trapezoid&& other) noexcept;

    virtual Points geometricalCenter() const override;
    virtual double area() const override;

    Trapezoid& operator=(const Trapezoid& other);
    Trapezoid& operator=(Trapezoid&& other) noexcept;
    bool operator==(const Trapezoid& other) const;

    virtual Figure& operator=(const Figure& other) override;
    virtual Figure& operator=(Figure&& other) noexcept override;
    virtual bool operator==(const Figure& other) const override;
    virtual operator double() const override;

    virtual Trapezoid* clone() const override;

    virtual ~Trapezoid() = default;
};

#endif
