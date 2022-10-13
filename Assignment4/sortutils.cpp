#include "sortutils.hpp"

#include <array>
#include <iostream>

void initializeRawArrayFromStdArray(const SourceArray& source, int dest[])
{
    for (int i = 0; i < source.size(); i++)
    {
        dest[i] = source[i];
    }
}
void organPipeStdArray(SourceArray& data)
{
}
void evaluateRawArray(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated)
{
}
void evaluateStdArray(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated)
{
}
void evaluateStdVector(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated)
{
}