環境建置
==========
此章節將以以下順序來進行說明：

 * 選擇ubuntu映像檔下載
 * 燒錄usb開機碟
 * 安裝ubuntu
 * 更新ubuntu及安裝所需軟體
 

選擇ubuntu映像檔下載
--------------------
以下提供三個版本讓使用者下載,分別是``ubuntu``,``ubuntu-mate``,``Linux Mint``,都測試過可以運行ROS。
差別上就是桌面環境不太一樣,使用者可以自行挑選下載,但是Mint是基於ubuntu而衍生的版本,要注意安裝ROS指令上要修改。

 * `ubuntu <http://ftp.tku.edu.tw/Linux/Ubuntu/ubuntu-releases/16.04/ubuntu-16.04.5-desktop-amd64.iso>`_
 * `ubuntu-mate <http://cdimage.ubuntu.com/ubuntu-mate/releases/16.04/release/ubuntu-mate-16.04-desktop-amd64.iso>`_
 * `Linux Mint <http://ftp.tku.edu.tw/Linux/LinuxMint/linuxmint-iso/stable/18.2/linuxmint-18.2-cinnamon-64bit.iso>`_

燒錄usb開機碟
---------------------
如果映像檔下載完成後,首先點選 `Rufus`_ 連結下載此軟體並準備一顆大於映像檔大小的隨身碟，然後開啟軟體後會看到以下畫面，依照軟體畫面從上而下，首先裝置只要有USB連接都會顯示出來,資料分割方式,系統及單元大小則按照圖中的設定就可。

.. figure:: image/usb_0.jpg

再來則是點選圖中紅框的光碟機，請選擇前面下載好的映像檔後，然後執行

.. figure:: image/usb_1.jpg


如果跳出以下這張圖，請選擇ISO，然後ok繼續。

.. figure:: image/usb_2.jpg


.. _Rufus: https://rufus.ie/en_IE.html





































