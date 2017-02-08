#ifndef UEQUERIES_H
#define UEQUERIES_H

#include <QString>

namespace UeQueries
{
    namespace UeTablePlaces
    {
        static const QString SQL_QUERY_GET_ALL_PLACES="SELECT P.ID AS PLACE_ID, P.NAME AS PLACE_NAME, P.X AS PLACE_X, P.Y AS PLACE_Y, F.NAME AS FLOOR_NAME, F.IMAGE AS FLOOR_IMAGE FROM PLACES AS P JOIN FLOORS AS F ON P.FLOOR=F.ID";
    }   // namespace
}   // namespace

#endif // UEQUERIES_H
