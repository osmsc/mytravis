#===========================================================================
#    
# Copyright (c) 2014-2015 The Regents of the University of California.
# All Rights Reserved. 
#
# Copyright (c) 2009-2011 Open Source Medical Software Corporation,
#                         University of California, San Diego.
#
# Portions of the code Copyright (c) 1998-2007 Stanford University,
# Charles Taylor, Nathan Wilson, Ken Wang.
#
# See SimVascular Acknowledgements file for additional
# contributors to the source code. 
#
# Permission is hereby granted, free of charge, to any person obtaining
# a copy of this software and associated documentation files (the
# "Software"), to deal in the Software without restriction, including 
# without limitation the rights to use, copy, modify, merge, publish, 
# distribute, sublicense, and/or sell copies of the Software, and to
# permit persons to whom the Software is furnished to do so, subject
# to the following conditions:
# 
# The above copyright notice and this permission notice shall be included 
# in all copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
# OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
# IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
# CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
# TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
# SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#
#===========================================================================    


proc vis_pointWidgetAdd [list ren input name EnableEvent StartInteractionEvent \
                              InteractionEvent EndInteractionEvent] {

  set interactor "vis_pointWidget_interactor_$ren\_$name"
  # create interactive cursor
  catch {$interactor Delete}
  vtkPointWidget $interactor
  $interactor SetInputData $input
  $interactor AllOff
  $interactor PlaceWidget

  set iren genericInteractor_$ren

  # Associate the point widget with the interactor
  $interactor SetInteractor $iren
  $interactor EnabledOff
  $interactor AddObserver EnableEvent $EnableEvent
  $interactor AddObserver StartInteractionEvent $StartInteractionEvent
  $interactor AddObserver InteractionEvent $InteractionEvent
  $interactor AddObserver EndInteractionEvent $EndInteractionEvent

  global gRen3d
  global gRen3dCopies
  if {$ren == $gRen3d} {
    foreach ren $gRen3dCopies {
      set interactor "vis_pointWidget_interactor_$ren\_$name"
      # create interactive cursor
      catch {$interactor Delete}
      vtkPointWidget $interactor
      $interactor SetInputData $input
      $interactor AllOff
      $interactor PlaceWidget

      set iren genericInteractor_$ren

      # Associate the point widget with the interactor
      $interactor SetInteractor $iren
      $interactor EnabledOff
      $interactor AddObserver EnableEvent $EnableEvent
      $interactor AddObserver StartInteractionEvent $StartInteractionEvent
      $interactor AddObserver InteractionEvent $InteractionEvent
      $interactor AddObserver EndInteractionEvent $EndInteractionEvent
    }
  }

}

proc vis_pointWidgetRm {ren name} {
  set interactor "vis_pointWidget_interactor_$ren\_$name"
  vis_pointWidgetOff $ren $name
  $interactor Delete
  global gRen3d
  global gRen3dCopies
  if {$ren == $gRen3d} {
    foreach ren $gRen3dCopies {
      set interactor "vis_pointWidget_interactor_$ren\_$name"
      #vis_pointWidgetOff $ren $name
      $interactor Delete
    }
  }
}

proc vis_pointWidgetOn {ren name} {
  set interactor "vis_pointWidget_interactor_$ren\_$name"
  $interactor EnabledOn
  global gRen3d
  global gRen3dCopies
  if {$ren == $gRen3d} {
    foreach ren $gRen3dCopies {
      set interactor "vis_pointWidget_interactor_$ren\_$name"
      $interactor EnabledOn
    }
  }
}

proc vis_pointWidgetOff {ren name} {
  set interactor "vis_pointWidget_interactor_$ren\_$name"
  $interactor EnabledOff
  global gRen3d
  global gRen3dCopies
  if {$ren == $gRen3d} {
    foreach ren $gRen3dCopies {
      set interactor "vis_pointWidget_interactor_$ren\_$name"
      $interactor EnabledOff
    }
  }
}

proc vis_pointWidgetSetPosition {ren name x y z} {
  set interactor "vis_pointWidget_interactor_$ren\_$name"
  $interactor SetPosition $x $y $z
  global gRen3d
  global gRen3dCopies
  if {$ren == $gRen3d} {
    foreach ren $gRen3dCopies { 
      set interactor "vis_pointWidget_interactor_$ren\_$name"
      $interactor SetPosition $x $y $z
    }
  }
}

proc vis_pointWidgetGetPosition {ren name} {
  set interactor "vis_pointWidget_interactor_$ren\_$name"
  return [$interactor GetPosition]
}







