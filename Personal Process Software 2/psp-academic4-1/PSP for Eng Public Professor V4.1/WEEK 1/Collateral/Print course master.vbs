' Script for printing course master

' This script should be in the "Collateral" folder, if it is not it will terminate

' Print output goes to the default printer

' This script has no error handling or recovery
' If an error occurs, the script will terminate



DIM fullname
DIM path
Dim sfolder
DIM position
Const wdDoNotSaveChanges = 0

' Returns path to the current script
fullname = WScript.ScriptFullName  ' script file name
position = InStrRev(fullname, "\") -1
path = Left(fullname, position)
position = Len(path)-InStrRev(path, "\")
sfolder = Right(path, position)
path = Left(path, InStrRev(path, "\")) 'path for handouts, must be modified for printing the notebook

If (sfolder = "Collateral") then

   If MsgBox("Print course handouts and instructor materials?", 4, "PSP for Engineers I") = 6 then
   
    ' Print Handouts 
  

    ' Print Instructor materials
      
   End If 'print handouts and instructor materials



   If MsgBox("Print course notebook?", 4, "PSP for Engineers I") = 6 then

    ' set the path for the notebook print
      path = path & "Course notebook\"

    ' print the spine and cover 

        SlidePrint "Cover and Spines\Spine Bndr.ppt"
        SlidePrint "Cover and Spines\Cover Page.ppt"

    ' print contents tab and contents
        DocPrint "Tabs\1tab Contents and Schedule.doc"
        DocPrint "Notebook Contents\Contents\Contents.doc"

    ' print day 1
        DocPrint "Tabs\2tab Week 1 Day 1.doc"
        HandoutPrint "Notebook Contents\Week1Day1\Course Overview I.ppt"
        DocPrint "Notebook Contents\Week1Day1\Intro EX.doc"
 	HandoutPrint "Notebook Contents\Week1Day1\L1 Introduction to PSP.ppt"
        HandoutPrint "Notebook Contents\Week1Day1\Using PSP0.ppt"
        DocPrint "Notebook Contents\Week1Day1\ASGKIT PROG1.doc"

    
    ' print day 2
        DocPrint "Tabs\3tab Week 1 Day 2.doc"
        HandoutPrint "Notebook Contents\Week1Day2\L2 Process Measurement.ppt"
        DocPrint "Notebook Contents\Week1Day2\ASGKIT Counting Std.doc"
	DocPrint "Notebook Contents\Week1Day2\ASGKIT Coding Std.doc"
	HandoutPrint "Notebook Contents\Week1Day2\Using PSP0.1.ppt"
        DocPrint "Notebook Contents\Week1Day2\ASGKIT PROG2.doc"


    ' print day 3
        DocPrint "Tabs\4tab Week 1 Day 3.doc"
        HandoutPrint "Notebook Contents\Week1Day3\L3 PROBE I.ppt"
	HandoutPrint "Notebook Contents\Week1Day3\Using PSP1.ppt"
        DocPrint "Notebook Contents\Week1Day3\ASGKIT PROG3.doc"


    ' print day 4
        DocPrint "Tabs\5tab Week 1 Day 4.doc"
        HandoutPrint "Notebook Contents\Week1Day4\L4 PROBE II.ppt"
        HandoutPrint "Notebook Contents\Week1Day4\Using PSP1.1.ppt"
        DocPrint "Notebook Contents\Week1Day4\ASGKIT PROG4.doc"

    ' print day 5
        DocPrint "Tabs\6tab Week 1 Day 5.doc"
        HandoutPrint "Notebook Contents\Week1Day5\L5 Using PSP Data.ppt"
        DocPrint "Notebook Contents\Week1Day5\ASGKIT Interim Report.doc"
	DocPrint "Notebook Contents\Week1Day5\ASGKIT Review Checklists.doc"
      
   End If 'print course notebook

Else 
   Wscript.echo "Script not in Collateral folder"
End If 'script in Collateral folder


Sub DocPrint (subpath)
   Set objWord = CreateObject("Word.Application")
   Set objDoc = objWord.Documents.Open(path & subpath)
   objWord.Options.PrintBackground = False
   objDoc.PrintOut()
   objDoc.Close wdDoNotSaveChanges
   objWord.Quit
End Sub


Sub SlidePrint (subpath)
   Dim objppt
   Dim objPresentation
   Set objppt = Wscript.CreateObject("PowerPoint.Application")
   Set objPresentation = objppt.Presentations.Open(path & subpath,,,False)
   with objPresentation
      with .PrintOptions
         .PrintInBackground = False
         .FrameSlides = False
         .FittoPage = False
         .OutputType = 1       '1 up slide
         .PrintColorType = 2   'Black & white output
      end With
     .PrintOut()
   end With
   objppt.Quit
End Sub

Sub HandoutPrint (subpath)
   Dim objppt
   Dim objPresentation
   Set objppt = Wscript.CreateObject("PowerPoint.Application")
   Set objPresentation = objppt.Presentations.Open(path & subpath,,,False)
   with objPresentation
      with .PrintOptions
         .PrintInBackground = False
         .FrameSlides = True
         .FittoPage = True
         .OutputType = 2       '2 up slide
         .PrintColorType = 2   'Black & white output
      end With
     .PrintOut()
   end With
   objppt.Quit
End Sub


