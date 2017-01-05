/* Copyright (c) 2009-2011 Open Source Medical Software Corporation,
 *                         University of California, San Diego.
 *
 * All rights reserved.
 *
 * Portions of the code Copyright (c) 1998-2007 Stanford University,
 * Charles Taylor, Nathan Wilson, Ken Wang.
 *
 * See SimVascular Acknowledgements file for additional
 * contributors to the source code. 
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including 
 * without limitation the rights to use, copy, modify, merge, publish, 
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject
 * to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included 
 * in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef __CVVTKUTILS_H
#define __CVVTKUTILS_H


#include "cvVTK.h"
#include "cv_cgeom.h"

#include "SimVascular.h"

int SV_EXPORT_UTILS VtkUtils_NewVtkPolyData( vtkPolyData **pd, int numPts, vtkFloatingPointType pts[],
			     int numCells, vtkIdType polys[] );

int SV_EXPORT_UTILS VtkUtils_NewVtkPolyDataLines( vtkPolyData **pd, int numPts, vtkFloatingPointType pts[],
				  int numLines, vtkIdType lines[] );

// What I'd like to do in FixTopology is clean up the vtkPolyData *pd
// in-place, returning the modified structure to the caller in pd.
// But it's UTTERLY unclear to me how to make changes to the point
// list in vtkPolyData.  MAYBE what I should do is make a new
// vtkCellArray to use as vtkPolyData::Verts, and then make new Lines
// and Polys which use indices into that new Verts array.  This does
// NOT seem like it would actually DELETE any of the redundant points
// that we're trying to get rid of in the vtkPoints member inherited
// from the vtkPointSet parent class.  But it WOULD eliminate
// references to those redundant points by the topology.  And
// actually, Verts does not seem to be important.  So just keep the
// same (potentially redundant) point set, and just change the id's
// that get used by Lines and Polys.

int SV_EXPORT_UTILS VtkUtils_FixTopology( vtkPolyData *pd, double tol );

int SV_EXPORT_UTILS VtkUtils_GetPoints( vtkPolyData *pd, double **pts, int *numPts );

int SV_EXPORT_UTILS VtkUtils_GetPointsFloat( vtkPolyData *pd, vtkFloatingPointType **pts, int *numPts );

int SV_EXPORT_UTILS VtkUtils_GetAllLines( vtkPolyData *pd, int *numLines, vtkIdType **lines );

int SV_EXPORT_UTILS VtkUtils_GetAllPolys( vtkPolyData *pd, int *numPgns, vtkIdType **pgns );

int SV_EXPORT_UTILS VtkUtils_GetLines( vtkPolyData *pd, vtkIdType **lines, int *numLines );

int SV_EXPORT_UTILS VtkUtils_GetLinkedLines( vtkIdType *lines, int numLines, int ptIx,
			     int **lineIxs, int *numLineIxs );

int SV_EXPORT_UTILS VtkUtils_FindClosedLineRegions( vtkIdType *lines, int numLines, int numPts,
				    int **startIxs, int *numRegions );

int SV_EXPORT_UTILS VtkUtils_GetClosedLineRegion( vtkIdType *lines, int numLines, int startIx,
				  int **lineIds, int *numLineIds );

int SV_EXPORT_UTILS VtkUtils_MakePolyDataFromLineIds( double *pts, int numPts, vtkIdType *lines,
				      int *lineIds, int numLineIds,
				      vtkPolyData **pd );

int SV_EXPORT_UTILS VtkUtils_MakeShortArray( vtkDataArray *s, int *num, short **dataOut );

int SV_EXPORT_UTILS VtkUtils_MakeFloatArray( vtkDataArray *s, int *num, float **dataOut );

SV_EXPORT_UTILS vtkPoints* VtkUtils_DeepCopyPoints( vtkPoints *ptsIn );

SV_EXPORT_UTILS vtkCellArray* VtkUtils_DeepCopyCells( vtkCellArray *cellsIn );

int SV_EXPORT_UTILS VtkUtils_MakePolysConsistent( vtkPolyData *pd );

int SV_EXPORT_UTILS VtkUtils_ReverseAllCells( vtkPolyData *pd );

int SV_EXPORT_UTILS VtkUtils_GetOrderedPoints(vtkPolyData *inputData, int direction,  double **pts, int *numPts);

int SV_EXPORT_UTILS VtkUtils_CalcDirection(double *pts, int numPts, int *currentDirection);

int SV_EXPORT_UTILS VtkUtils_ReversePtList( int num, double ptsIn[], double *ptsOut[] );

int SV_EXPORT_UTILS VtkUtils_PDCheckArrayName( vtkPolyData *object, int datatype,std::string arrayname);

int SV_EXPORT_UTILS VtkUtils_UGCheckArrayName( vtkUnstructuredGrid *object, int datatype,std::string arrayname);
#endif // __CVVTKUTILS_H
