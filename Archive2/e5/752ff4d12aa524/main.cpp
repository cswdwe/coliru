#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>

void pkcs7_pad( unsigned char* data, unsigned char* dataOut, unsigned int& dataLength )
{
    if ( data != dataOut )
    {
        std::memcpy( dataOut, data, dataLength );
    }
    
    char padChar = 8 - ( dataLength % 8 );
    for ( int i = 0; i < padChar; ++i )
    {
        dataOut[ dataLength++ ] = ( char )padChar;
    }
}

void printBytes( unsigned char* data, unsigned int length )
{
    unsigned int j = 0;
    while ( j < length )
    {
        for ( unsigned int i = 0; i < 8; ++i, ++j )
        {
            std::cout << std::setfill( '0' ) << std::setw( 2 ) << std::hex << ( int )data[ j ] << " ";
        }
        std::cout << std::endl;
    }
}

int main( int argc, char **argv )
{
    srand( time( NULL ) );
    
    unsigned int dataLength = 0;
    unsigned char* data;
    
    #define TEST_PADDING( a ) \
    { \
        dataLength = a; \
        data = new unsigned char[ ( int )( std::ceil( dataLength / 8 ) * 8 ) ]; \
        \
        for ( unsigned int i = 0; i < dataLength; ++i ) \
        { \
            data[ i ] = rand(  ) % 255; \
        } \
        \
        pkcs7_pad( data, data, dataLength ); \
        printBytes( data, dataLength ); \
        std::cout << std::endl; \
        \
        delete[] data; \
        dataLength = 0; \
    }
    
    for ( int i = 0; i < 100; ++i )
    {
        TEST_PADDING( ( rand(  ) % 16 ) + 1 );
    }
 
    return 0;
}