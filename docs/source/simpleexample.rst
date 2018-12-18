建立ROS WorkSpace
==================
當在建置一個機器人的系統可能有許多感知、導航、控制等程式，這幾個都是分別開發、測試，最後在整合。
所以首先建立一個環境，當在這環境下編譯，只會編譯在這環境下的專案，在ROS下，稱為workspace。
首先建立一個存放工作空間的資料夾，可依照自己方便辨別的名稱，這裡我用dev來當存放工作空間的目錄，並建立一個名稱為 ``ros_tutorial_ws`` 的工作空間::

	$ mkdir -p ~/dev/ros_turtorial_ws/src

建立好資料夾後,進入 src資料夾, 初始化工作空間::

  $ catkin_init_workspace

再回到上一層 ``ros_tutorial_ws`` 資料夾, 做建置動作::

  $ cd .. && catkin_make

.. note::
  如果建制完成後,想到執行此工作空間下的可執行節點(Node),要做一次Source的動作,記得每重開一次終端機(terminal)都要做一次::

  $　source ~/dev/ros_tutorial_ws/devel/setup.bash


Topic範例
====================



建立package
--------------------







 
