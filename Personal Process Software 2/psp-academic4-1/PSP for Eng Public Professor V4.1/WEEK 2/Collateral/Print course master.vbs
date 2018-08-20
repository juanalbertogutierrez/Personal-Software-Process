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

   If MsgBox("Print course handouts and instructor materials?", 4, "PSP for Engineers II") = 6 then
   
    ' Print Handouts 
     '   DocPrint "Handouts\Student CD\Final Report Templates.doc"
  

    ' Print Instructor materials
      
   End If 'print handouts and instructor materials



   If MsgBox("Print course notebook?", 4, "PSP for Engineers II") = 6 then

    ' set the path for the notebook print
      path = path & "Course notebook\"

    ' print the spine and cover 

        SlidePrint "Cover and Spines\Spine Bndr.ppt"
        SlidePrint "Cover and Spines\Cover Page.ppt"

    ' print contents tab and contents
        DocPrint "Tabs\1tab Contents and Schedule.doc"
        DocPrint "Notebook Contents\Contents\Contents.doc"

    ' print day 1
        DocPrint "Tabs\2tab Week 2 Day 6.doc"
        HandoutPrint "Notebook Contents\Week2Day6\Course Overview II.ppt"
        HandoutPrint "Notebook Contents\Week2Day6\L6 Software quality.ppt"
        HandoutPrint "Notebook Contents\Week2Day6\Using PSP2.ppt"
        DocPrint "Notebook Contents\Week2Day6\ASGKIT PROG5.doc"

    
    ' print day 2
        DocPrint "Tabs\3tab Week 2 Day 7.doc"
        HandoutPrint "Notebook Contents\Week2Day7\L7 Software Design I.ppt"
        HandoutPrint "Notebook Contents\Week2Day7\Using PSP2.1.ppt"
        DocPrint "Notebook Contents\Week2Day7\ASGKIT PROG6.doc"


    ' print day 3
        DocPrint "Tabs\4tab Week 2 Day 8.doc"
        HandoutPrint "Notebook Contents\Week2Day8\L8 Software Design II.ppt"
        DocPrint "Notebook Contents\Week2Day8\State Machine Verification EX.doc"
        DocPrint "Notebook Contents\Week2Day8\ASGKIT PROG7.doc"


    ' print day 4
        DocPrint "Tabs\5tab Week 2 Day 9.doc"
        HandoutPrint "Notebook Contents\Week2Day9\L9 Design verification.ppt"
        DocPrint "Notebook Contents\Week2Day9\Design Ver. EX.doc"
        DocPrint "Notebook Contents\Week2Day9\ASGKIT PROG8.doc"

    ' print day 5
        DocPrint "Tabs\6tab Week 2 Day 10.doc"
        HandoutPrint "Notebook Contents\Week2Day10\L10 Using the PSP.ppt"
        DocPrint "Notebook Contents\Week2Day10\ASGKIT Final Report .doc"

      
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


