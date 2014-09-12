#ifndef CONSTANTES_HPP_INCLUDED
#define CONSTANTES_HPP_INCLUDED

const float BOX2D_SIZE_REDUCTION = 100.f;

// Foncteur servant à libérer un pointeur - applicable à n'importe quel type
struct Delete
{
   template <class T> void operator ()(T*& p) const
   {
      delete p;
      p = 0;
   }
};

#endif // CONSTANTES_HPP_INCLUDED
