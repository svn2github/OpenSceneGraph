#include <osg/Matrix>
#include <osg/Quat>
#include <osg/Notify>
#include <osg/Types>
#include <osg/Math>

#include <stdlib.h>

using namespace osg;

#define SET_ROW(row, v1, v2, v3, v4 )    \
    _mat[(row)][0] = (v1); \
    _mat[(row)][1] = (v2); \
    _mat[(row)][2] = (v3); \
    _mat[(row)][3] = (v4);

#define INNER_PRODUCT(a,b,r,c) \
     ((a)._mat[r][0] * (b)._mat[0][c]) \
    +((a)._mat[r][1] * (b)._mat[1][c]) \
    +((a)._mat[r][2] * (b)._mat[2][c]) \
    +((a)._mat[r][3] * (b)._mat[3][c])


Matrix::Matrix() : Object()
{
    makeIdentity();
}

Matrix::Matrix( const Matrix& other) : Object()
{
    set( (const float *) other._mat );
}

Matrix::Matrix( const float * def )
{    
    set( def ); 
}

Matrix::Matrix( float a00, float a01, float a02, float a03,
                float a10, float a11, float a12, float a13,
                float a20, float a21, float a22, float a23,
                float a30, float a31, float a32, float a33)
{
    SET_ROW(0, a00, a01, a02, a03 )
    SET_ROW(1, a10, a11, a12, a13 )
    SET_ROW(2, a20, a21, a22, a23 )
    SET_ROW(3, a30, a31, a32, a33 )
}


Matrix& Matrix::operator = (const Matrix& other )
{
    if( &other == this ) return *this;
    set((const float*)other._mat);
    return *this;
}

void Matrix::set( float const * const def )
{
    memcpy( _mat, def, sizeof(_mat) );
}


void Matrix::set( float a00, float a01, float a02, float a03,
                  float a10, float a11, float a12, float a13,
                  float a20, float a21, float a22, float a23,
                  float a30, float a31, float a32, float a33)
{
    SET_ROW(0, a00, a01, a02, a03 )
    SET_ROW(1, a10, a11, a12, a13 )
    SET_ROW(2, a20, a21, a22, a23 )
    SET_ROW(3, a30, a31, a32, a33 )
}

void Matrix::setTrans( float tx, float ty, float tz )
{
    _mat[3][0] = tx;
    _mat[3][1] = ty;
    _mat[3][2] = tz;
}


void Matrix::setTrans( const Vec3& v )
{
    _mat[3][0] = v[0];
    _mat[3][1] = v[1];
    _mat[3][2] = v[2];
}

void Matrix::makeIdentity()
{
    SET_ROW(0,    1, 0, 0, 0 )
    SET_ROW(1,    0, 1, 0, 0 )
    SET_ROW(2,    0, 0, 1, 0 )
    SET_ROW(3,    0, 0, 0, 1 )
}

void Matrix::makeScale( const Vec3& v )
{
    makeScale(v[0], v[1], v[2] );
}

void Matrix::makeScale( float x, float y, float z )
{
    SET_ROW(0,    x, 0, 0, 0 )
    SET_ROW(1,    0, y, 0, 0 )
    SET_ROW(2,    0, 0, z, 0 )
    SET_ROW(3,    0, 0, 0, 1 )
}

void Matrix::makeTranslate( const Vec3& v )
{
    makeTranslate( v[0], v[1], v[2] );
}

void Matrix::makeTranslate( float x, float y, float z )
{
    SET_ROW(0,    1, 0, 0, 0 )
    SET_ROW(1,    0, 1, 0, 0 )
    SET_ROW(2,    0, 0, 1, 0 )
    SET_ROW(3,    x, y, z, 1 )
}

void Matrix::makeRotate( const Vec3& from, const Vec3& to )
{
    Quat quat;
    quat.makeRotate(from,to);
    quat.get(*this);
}

void Matrix::makeRotate( float angle, const Vec3& axis )
{
    Quat quat;
    quat.makeRotate( angle, axis);
    quat.get(*this);
}

void Matrix::makeRotate( float angle, float x, float y, float z ) 
{
    Quat quat;
    quat.makeRotate( angle, x, y, z);
    quat.get(*this);
}

void Matrix::makeRotate( const Quat& q )
{
    q.get(*this);    
}

void Matrix::makeRotate( float yaw, float pitch, float roll)
{

    // lifted straight from SOLID library v1.01 Quaternion.h
    // available from http://www.win.tue.nl/~gino/solid/
    // and also distributed under the LGPL
    float cosYaw = cos(yaw / 2);
    float sinYaw = sin(yaw / 2);
    float cosPitch = cos(pitch / 2);
    float sinPitch = sin(pitch / 2);
    float cosRoll = cos(roll / 2);
    float sinRoll = sin(roll / 2);
    Quat q(sinRoll * cosPitch * cosYaw - cosRoll * sinPitch * sinYaw,
            cosRoll * sinPitch * cosYaw + sinRoll * cosPitch * sinYaw,
            cosRoll * cosPitch * sinYaw - sinRoll * sinPitch * cosYaw,
            cosRoll * cosPitch * cosYaw + sinRoll * sinPitch * sinYaw);
            
    q.get(*this);
}

void Matrix::mult( const Matrix& lhs, const Matrix& rhs )
{   

// PRECONDITION: We assume neither &lhs nor &rhs == this
// if it did, use preMult or postMult instead
    _mat[0][0] = INNER_PRODUCT(lhs, rhs, 0, 0);
    _mat[0][1] = INNER_PRODUCT(lhs, rhs, 0, 1);
    _mat[0][2] = INNER_PRODUCT(lhs, rhs, 0, 2);
    _mat[0][3] = INNER_PRODUCT(lhs, rhs, 0, 3);
    _mat[1][0] = INNER_PRODUCT(lhs, rhs, 1, 0);
    _mat[1][1] = INNER_PRODUCT(lhs, rhs, 1, 1);
    _mat[1][2] = INNER_PRODUCT(lhs, rhs, 1, 2);
    _mat[1][3] = INNER_PRODUCT(lhs, rhs, 1, 3);
    _mat[2][0] = INNER_PRODUCT(lhs, rhs, 2, 0);
    _mat[2][1] = INNER_PRODUCT(lhs, rhs, 2, 1);
    _mat[2][2] = INNER_PRODUCT(lhs, rhs, 2, 2);
    _mat[2][3] = INNER_PRODUCT(lhs, rhs, 2, 3);
    _mat[3][0] = INNER_PRODUCT(lhs, rhs, 3, 0);
    _mat[3][1] = INNER_PRODUCT(lhs, rhs, 3, 1);
    _mat[3][2] = INNER_PRODUCT(lhs, rhs, 3, 2);
    _mat[3][3] = INNER_PRODUCT(lhs, rhs, 3, 3);
}

void Matrix::preMult( const Matrix& other )
{
    // brute force method requiring a copy
    //Matrix tmp(other* *this);
    // *this = tmp;

    // more efficient method just use a float[4] for temporary storage.
    float t[4];
    for(int col=0; col<4; ++col) {
        t[0] = INNER_PRODUCT( other, *this, 0, col );
        t[1] = INNER_PRODUCT( other, *this, 1, col );
        t[2] = INNER_PRODUCT( other, *this, 2, col );
        t[3] = INNER_PRODUCT( other, *this, 3, col );
        _mat[0][col] = t[0];
        _mat[1][col] = t[1];
        _mat[2][col] = t[2];
        _mat[3][col] = t[3];
    }

}

void Matrix::postMult( const Matrix& other )
{
    // brute force method requiring a copy
    //Matrix tmp(*this * other);
    // *this = tmp;

    // more efficient method just use a float[4] for temporary storage.
    float t[4];
    for(int row=0; row<4; ++row)
    {
        t[0] = INNER_PRODUCT( *this, other, row, 0 );
        t[1] = INNER_PRODUCT( *this, other, row, 1 );
        t[2] = INNER_PRODUCT( *this, other, row, 2 );
        t[3] = INNER_PRODUCT( *this, other, row, 3 );
        SET_ROW(row, t[0], t[1], t[2], t[3] )
    }
}

#undef SET_ROW
#undef INNER_PRODUCT

bool Matrix::invert( const Matrix& other )
{
    if (&other==this) 
    {
        Matrix tm(other);
        return invert(tm);
    }

//     if (   other._mat[0][3] == 0.0 
//         && other._mat[1][3] == 0.0 
//         && other._mat[2][3] == 0.0 
//         && other._mat[3][3] == 1.0 )
//     {
//         return invertAffine( other );
//     }

    // code lifted from VR Juggler.
    // not cleanly added, but seems to work.  RO.
    const float*  a = reinterpret_cast<const float*>(other._mat);
    float*  b = reinterpret_cast<float*>(_mat);

    int     n = 4;
    int     i, j, k;
    int     r[ 4], c[ 4], row[ 4], col[ 4];
    float  m[ 4][ 4*2], pivot, maxother, tmpother, fac;

    /* Initialization */
    for ( i = 0; i < n; i ++ )
    {
        r[ i] = c[ i] = 0;
        row[ i] = col[ i] = 0;
    }

    /* Set working Matrix */
    for ( i = 0; i < n; i++ )
    {
        for ( j = 0; j < n; j++ )
        {
            m[ i][ j] = a[ i * n + j];
            m[ i][ j + n] = ( i == j ) ? 1.0 : 0.0 ;
        }
    }

    /* Begin of loop */
    for ( k = 0; k < n; k++ )
    {
        /* Choosing the pivot */
        for ( i = 0, maxother = 0; i < n; i++ )
        {
            if ( row[ i]  ) continue;
            for ( j = 0; j < n; j++ )
            {
                if ( col[ j] ) continue;
                tmpother = fabs( m[ i][j]);
                if ( tmpother > maxother)
                {
                    maxother = tmpother;
                    r[ k] = i;
                    c[ k] = j;
                }
            }
        }
        row[ r[k] ] = col[ c[k] ] = 1;
        pivot = m[ r[ k] ][ c[ k] ];

        if ( fabs( pivot) <= 1e-20)
        {
            notify(WARN) << "Warning: pivot = "<< pivot <<" in Matrix::invert(), cannot compute inverse."<<std::endl;
            notify(WARN) << "input matrix to Matrix::invert() was = "<< other <<std::endl;
            makeIdentity();
            return false;
        }

        /* Normalization */
        for ( j = 0; j < 2*n; j++ )
        {
            if ( j == c[ k] )
                m[ r[ k]][ j] = 1.0;
            else
                m[ r[ k]][ j] /=pivot;
        }

        /* Reduction */
        for ( i = 0; i < n; i++ )
        {
            if ( i == r[ k] )
                continue;

            for ( j=0, fac = m[ i][ c[k]];j < 2*n; j++ )
            {
                if ( j == c[ k] )
                    m[ i][ j] =0.0;
                else
                    m[ i][ j] -=fac * m[ r[k]][ j];
            }
        }
    }

    /* Assign invers to a Matrix */
    for ( i = 0; i < n; i++ )
        for ( j = 0; j < n; j++ )
            row[ i] = ( c[ j] == i ) ? r[j] : row[ i];

    for ( i = 0; i < n; i++ )
        for ( j = 0; j < n; j++ )
            b[ i * n +  j] = m[ row[ i]][j + n];

    return true;                 // It worked
}

const double PRECISION_LIMIT = 1.0e-15;

bool Matrix::invertAffine( const Matrix& other )
{
    // adapted from Graphics Gems II.
    // 
    // This method treats the Matrix as a block Matrix and calculates
    // the inverse of one subMatrix, improving performance over something
    // that inverts any non-singular Matrix:
    //                           -1
    //    -1    [ A  0 ] -1    [ A    0 ]
    //   M   =  [      ]    =  [   -1   ]
    //          [ C  1 ]       [-CA   1 ]
    //
    // returns true if _m is nonsingular, and (*this) contains its inverse
    // otherwise returns false. (*this unchanged)

    // assert( this->isAffine())?
    double det_1, pos, neg, temp;

    pos = neg = 0.0;

#define ACCUMULATE \
    { \
        if(temp >= 0.0) pos += temp; \
        else neg += temp; \
    }

    temp = other._mat[0][0] * other._mat[1][1] * other._mat[2][2]; ACCUMULATE;
    temp = other._mat[0][1] * other._mat[1][2] * other._mat[2][0]; ACCUMULATE;
    temp = other._mat[0][2] * other._mat[1][0] * other._mat[2][1]; ACCUMULATE;

    temp = - other._mat[0][2] * other._mat[1][1] * other._mat[2][0]; ACCUMULATE;
    temp = - other._mat[0][1] * other._mat[1][0] * other._mat[2][2]; ACCUMULATE;
    temp = - other._mat[0][0] * other._mat[1][2] * other._mat[2][1]; ACCUMULATE;

    det_1 = pos + neg;

    if( (det_1 == 0.0) || (fabs(det_1/(pos-neg)) < PRECISION_LIMIT )) {
        // _m has no inverse
        notify(WARN) << "Matrix::invert(): Matrix has no inverse." << std::endl;
        return false;
    }

    // inverse is adj(A)/det(A)
    det_1 = 1.0 / det_1;

    _mat[0][0] = (other._mat[1][1] * other._mat[2][2] - other._mat[1][2] * other._mat[2][1]) * det_1;
    _mat[1][0] = (other._mat[1][0] * other._mat[2][2] - other._mat[1][2] * other._mat[2][0]) * det_1;
    _mat[2][0] = (other._mat[1][0] * other._mat[2][1] - other._mat[1][1] * other._mat[2][0]) * det_1;
    _mat[0][1] = (other._mat[0][1] * other._mat[2][2] - other._mat[0][2] * other._mat[2][1]) * det_1;
    _mat[1][1] = (other._mat[0][0] * other._mat[2][2] - other._mat[0][2] * other._mat[2][0]) * det_1;
    _mat[2][1] = (other._mat[0][0] * other._mat[2][1] - other._mat[0][1] * other._mat[2][0]) * det_1;
    _mat[0][2] = (other._mat[0][1] * other._mat[1][2] - other._mat[0][2] * other._mat[1][1]) * det_1;
    _mat[1][2] = (other._mat[0][0] * other._mat[1][2] - other._mat[0][2] * other._mat[1][0]) * det_1;
    _mat[2][2] = (other._mat[0][0] * other._mat[1][1] - other._mat[0][1] * other._mat[1][0]) * det_1;

    // calculate -C * inv(A)
    _mat[3][0] = -(other._mat[3][0] * _mat[0][0] + other._mat[3][1] * _mat[1][0] + other._mat[3][2] * _mat[2][0] );
    _mat[3][1] = -(other._mat[3][0] * _mat[0][1] + other._mat[3][1] * _mat[1][1] + other._mat[3][2] * _mat[2][1] );
    _mat[3][2] = -(other._mat[3][0] * _mat[0][2] + other._mat[3][1] * _mat[1][2] + other._mat[3][2] * _mat[2][2] );

    _mat[0][3] = 0.0;
    _mat[1][3] = 0.0;
    _mat[2][3] = 0.0;
    _mat[3][3] = 1.0;

    return true;
}

