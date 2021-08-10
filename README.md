
# BFME_Line_formation

## What is BFME? 

  Check out intro video/channel --> https://www.youtube.com/watch?v=MLLQLfExank 

Please follow the Code Syntax from BFME: Reforged for the task. This will help with the code review and to get yourself familiar with our approach.

Also, for your code to be reviewed it has to be in a GitHub repository. That way we can access the project, we also use GitHub ourselves.

The test task is a prototype, meaning everything apart from the test should not have priority nor do the visuals. In most cases it is recommend to start with Unreal's Top down template. For some tasks, if you really need a template that uses more RTS components than the basic UE4 templates, you may have a look at this UE4 RTS plugin. We actually use components from it as well 
Description
When selecting a target destination for unit(s) to move to, the player can right click drag the mouse to set units to arrange themselves in a formation at the target destination in front to back order dictated by unit category; melee, ranged, siege.
When setting the formation the player can see where units will be placed within the formation, identified through unit category specific decals.	


To do: feature interactions

The player holds right click whilst units are selected to define a formation.
The initial mouse cursor location when right clicked is the point in which the front of the formation is defined.
The frontward direction the units face can be rotated by moving the mouse left and right. The unit formation then pivots on target location.
The width and depth of the formation can be altered by moving the mouse up or down. Spreading units out further between each other with less lines of units, or with more lines of units with a greater depth (images provided below)
When the player releases right click, the units move to the appropriate positions.
Units do not move in formation, only to the target location to setup as a formation
The unit formation order prioritization for the test prototype should be as follows:
Front - Melee
Ranged - Middle
Siege - Back
Unit decals appear where in the formation the associated unit will be positioned.
If the player left clicks whilst holding down the right mouse with units selected the command is cancelled.

A flexible approach is preferable, taking into account the potential of more unit categories being required to be a part of unit formations, such as cavalry, heroes etc in the future. So a system that is flexible, able to handle classes we'd add later, is the target of the prototype.

  Player defining desired unit formation at arrow location. 
  
  
