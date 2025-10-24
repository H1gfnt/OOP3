#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Figure.h"
#include <cmath>

class Rectangle : public Figure {
    friend std::ostream &operator<<(std::ostream &stream, const Rectangle &rectangle);
    friend std::istream &operator>>(std::istream &stream, Rectangle &rectangle);
private:
    Points v_1, v_2, v_3, v_4;
    
    bool isValidRectangle(const Points& p1, const Points& p2, const Points& p3, const Points& p4) const;
    double distance(const Points& A, const Points& B) const;
    double dotProduct(const Points& A, const Points& B, const Points& C) const;
    bool arePerpendicular(const Points& A, const Points& B, const Points& C) const;
    
public:
    Rectangle() = default;
    Rectangle(const Points& p1, const Points& p2, const Points& p3, const Points& p4);
    Rectangle(const Rectangle& other);
    Rectangle(Rectangle&& other) noexcept;

    virtual Points geometricalCenter() const override;
    virtual double area() const override;

    Rectangle& operator=(const Rectangle& other);
    Rectangle& operator=(Rectangle&& other) noexcept;
    bool operator==(const Rectangle& other) const;

    virtual Figure& operator=(const Figure& other) override;
    virtual Figure& operator=(Figure&& other) noexcept override;
    virtual bool operator==(const Figure& other) const override;
    virtual operator double() const override;

    virtual Rectangle* clone() const override;

    virtual ~Rectangle() = default;
};

#endif
