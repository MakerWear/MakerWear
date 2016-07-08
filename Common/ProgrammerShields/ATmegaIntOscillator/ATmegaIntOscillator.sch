<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="7.3.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="16" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="50" name="dxf" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="14" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="53" name="tGND_GNDA" color="7" fill="9" visible="no" active="no"/>
<layer number="54" name="bGND_GNDA" color="1" fill="9" visible="no" active="no"/>
<layer number="56" name="wert" color="7" fill="1" visible="no" active="no"/>
<layer number="57" name="tCAD" color="7" fill="1" visible="no" active="no"/>
<layer number="59" name="tCarbon" color="7" fill="1" visible="no" active="no"/>
<layer number="60" name="bCarbon" color="7" fill="1" visible="no" active="no"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
<layer number="99" name="SpiceOrder" color="7" fill="1" visible="yes" active="yes"/>
<layer number="100" name="Muster" color="7" fill="1" visible="no" active="no"/>
<layer number="101" name="Patch_Top" color="12" fill="4" visible="no" active="yes"/>
<layer number="102" name="Vscore" color="7" fill="1" visible="no" active="yes"/>
<layer number="103" name="tMap" color="7" fill="1" visible="no" active="yes"/>
<layer number="104" name="Name" color="16" fill="1" visible="no" active="yes"/>
<layer number="105" name="tPlate" color="7" fill="1" visible="no" active="yes"/>
<layer number="106" name="bPlate" color="7" fill="1" visible="no" active="yes"/>
<layer number="107" name="Crop" color="7" fill="1" visible="no" active="yes"/>
<layer number="108" name="tplace-old" color="10" fill="1" visible="no" active="yes"/>
<layer number="109" name="ref-old" color="11" fill="1" visible="no" active="yes"/>
<layer number="110" name="fp0" color="7" fill="1" visible="no" active="yes"/>
<layer number="111" name="LPC17xx" color="7" fill="1" visible="no" active="yes"/>
<layer number="112" name="tSilk" color="7" fill="1" visible="no" active="yes"/>
<layer number="113" name="IDFDebug" color="4" fill="1" visible="no" active="yes"/>
<layer number="114" name="Badge_Outline" color="11" fill="1" visible="no" active="no"/>
<layer number="116" name="Patch_BOT" color="9" fill="4" visible="no" active="yes"/>
<layer number="118" name="Rect_Pads" color="7" fill="1" visible="yes" active="yes"/>
<layer number="121" name="_tsilk" color="7" fill="1" visible="no" active="yes"/>
<layer number="122" name="_bsilk" color="7" fill="1" visible="no" active="yes"/>
<layer number="123" name="tTestmark" color="7" fill="1" visible="no" active="yes"/>
<layer number="124" name="bTestmark" color="7" fill="1" visible="no" active="yes"/>
<layer number="125" name="_tNames" color="7" fill="1" visible="no" active="yes"/>
<layer number="126" name="_bNames" color="7" fill="1" visible="no" active="yes"/>
<layer number="127" name="_tValues" color="7" fill="1" visible="no" active="yes"/>
<layer number="128" name="_bValues" color="7" fill="1" visible="no" active="yes"/>
<layer number="129" name="Mask" color="7" fill="1" visible="yes" active="yes"/>
<layer number="131" name="tAdjust" color="7" fill="1" visible="no" active="yes"/>
<layer number="132" name="bAdjust" color="7" fill="1" visible="no" active="yes"/>
<layer number="144" name="Drill_legend" color="7" fill="1" visible="no" active="yes"/>
<layer number="150" name="Notes" color="7" fill="1" visible="no" active="yes"/>
<layer number="151" name="HeatSink" color="7" fill="1" visible="no" active="yes"/>
<layer number="152" name="_bDocu" color="7" fill="1" visible="no" active="yes"/>
<layer number="153" name="FabDoc1" color="7" fill="1" visible="no" active="yes"/>
<layer number="154" name="FabDoc2" color="7" fill="1" visible="no" active="yes"/>
<layer number="155" name="FabDoc3" color="7" fill="1" visible="no" active="yes"/>
<layer number="199" name="Contour" color="7" fill="1" visible="no" active="yes"/>
<layer number="200" name="200bmp" color="1" fill="10" visible="no" active="yes"/>
<layer number="201" name="201bmp" color="2" fill="10" visible="no" active="yes"/>
<layer number="202" name="202bmp" color="3" fill="10" visible="no" active="yes"/>
<layer number="203" name="203bmp" color="4" fill="10" visible="no" active="yes"/>
<layer number="204" name="204bmp" color="5" fill="10" visible="no" active="yes"/>
<layer number="205" name="205bmp" color="6" fill="10" visible="no" active="yes"/>
<layer number="206" name="206bmp" color="7" fill="10" visible="no" active="yes"/>
<layer number="207" name="207bmp" color="8" fill="10" visible="no" active="yes"/>
<layer number="208" name="208bmp" color="9" fill="10" visible="no" active="yes"/>
<layer number="209" name="209bmp" color="7" fill="1" visible="no" active="yes"/>
<layer number="210" name="210bmp" color="7" fill="1" visible="no" active="yes"/>
<layer number="211" name="211bmp" color="7" fill="1" visible="no" active="yes"/>
<layer number="212" name="212bmp" color="7" fill="1" visible="no" active="yes"/>
<layer number="213" name="213bmp" color="7" fill="1" visible="no" active="yes"/>
<layer number="214" name="214bmp" color="7" fill="1" visible="no" active="yes"/>
<layer number="215" name="215bmp" color="7" fill="1" visible="no" active="yes"/>
<layer number="216" name="216bmp" color="7" fill="1" visible="no" active="yes"/>
<layer number="217" name="217bmp" color="18" fill="1" visible="no" active="no"/>
<layer number="218" name="218bmp" color="19" fill="1" visible="no" active="no"/>
<layer number="219" name="219bmp" color="20" fill="1" visible="no" active="no"/>
<layer number="220" name="220bmp" color="21" fill="1" visible="no" active="no"/>
<layer number="221" name="221bmp" color="22" fill="1" visible="no" active="no"/>
<layer number="222" name="222bmp" color="23" fill="1" visible="no" active="no"/>
<layer number="223" name="223bmp" color="24" fill="1" visible="no" active="no"/>
<layer number="224" name="224bmp" color="25" fill="1" visible="no" active="no"/>
<layer number="225" name="225bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="226" name="226bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="227" name="227bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="228" name="228bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="229" name="229bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="230" name="230bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="231" name="231bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="232" name="Eagle3D_PG2" color="7" fill="1" visible="no" active="no"/>
<layer number="233" name="Eagle3D_PG3" color="7" fill="1" visible="no" active="no"/>
<layer number="248" name="Housing" color="7" fill="1" visible="no" active="yes"/>
<layer number="249" name="Edge" color="7" fill="1" visible="no" active="yes"/>
<layer number="250" name="Descript" color="3" fill="1" visible="no" active="no"/>
<layer number="251" name="SMDround" color="12" fill="11" visible="no" active="no"/>
<layer number="254" name="cooling" color="7" fill="1" visible="no" active="yes"/>
<layer number="255" name="routoute" color="7" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="SparkFun-Boards">
<description>&lt;h3&gt;SparkFun Electronics' preferred foot prints&lt;/h3&gt;
In this library you'll find boards and modules: Arduino footprints, breadboards, non-RF modules, etc.&lt;br&gt;&lt;br&gt;
We've spent an enormous amount of time creating and checking these footprints and parts, but it is the end user's responsibility to ensure correctness and suitablity for a given componet or application. If you enjoy using this library, please buy one of our products at www.sparkfun.com.
&lt;br&gt;&lt;br&gt;
&lt;b&gt;Licensing:&lt;/b&gt; Creative Commons ShareAlike 4.0 International - https://creativecommons.org/licenses/by-sa/4.0/ 
&lt;br&gt;&lt;br&gt;
You are welcome to use this library for commercial purposes. For attribution, we ask that when you begin to sell your device using our footprint, you email us with a link to the product being sold. We want bragging rights that we helped (in a very small part) to create your 8th world wonder. We would like the opportunity to feature your device on our homepage.</description>
<packages>
<package name="UNO_R3_SHIELD">
<description>Uno R3 Compatible Board Layout</description>
<wire x1="2.54" y1="0" x2="9.5" y2="0" width="0.254" layer="51"/>
<wire x1="9.5" y1="0" x2="21.7" y2="0" width="0.254" layer="51"/>
<wire x1="21.7" y1="0" x2="50.8" y2="0" width="0.254" layer="51"/>
<wire x1="50.8" y1="0" x2="53.34" y2="2.54" width="0.254" layer="51"/>
<wire x1="53.34" y1="57.15" x2="50.8" y2="57.15" width="0.254" layer="51"/>
<wire x1="50.8" y1="57.15" x2="48.26" y2="59.69" width="0.254" layer="51"/>
<wire x1="0" y1="55.88" x2="0" y2="2.54" width="0.254" layer="51"/>
<wire x1="0" y1="2.54" x2="2.54" y2="0" width="0.254" layer="51"/>
<wire x1="48.26" y1="59.69" x2="15.24" y2="59.69" width="0.254" layer="51"/>
<wire x1="15.24" y1="59.69" x2="12.7" y2="57.15" width="0.254" layer="51"/>
<wire x1="12.7" y1="57.15" x2="1.27" y2="57.15" width="0.254" layer="51"/>
<wire x1="1.27" y1="57.15" x2="0" y2="55.88" width="0.254" layer="51"/>
<wire x1="53.34" y1="2.54" x2="53.34" y2="57.15" width="0.254" layer="51"/>
<wire x1="9.5" y1="-15.5" x2="21.7" y2="-15.5" width="0.254" layer="51"/>
<wire x1="40.2" y1="-10.3" x2="49.2" y2="-10.3" width="0.254" layer="51"/>
<wire x1="9.5" y1="-15.5" x2="9.5" y2="0" width="0.254" layer="51"/>
<wire x1="21.7" y1="-15.5" x2="21.7" y2="0" width="0.254" layer="51"/>
<wire x1="40.2" y1="-10.3" x2="40.2" y2="-0.1" width="0.254" layer="51"/>
<wire x1="49.2" y1="-10.3" x2="49.2" y2="-0.1" width="0.254" layer="51"/>
<wire x1="1.27" y1="55.88" x2="3.81" y2="55.88" width="0.127" layer="51"/>
<wire x1="3.81" y1="55.88" x2="3.81" y2="35.56" width="0.127" layer="51"/>
<wire x1="3.81" y1="35.56" x2="1.27" y2="35.56" width="0.127" layer="51"/>
<wire x1="1.27" y1="35.56" x2="1.27" y2="55.88" width="0.127" layer="51"/>
<wire x1="1.27" y1="34.29" x2="3.81" y2="34.29" width="0.127" layer="51"/>
<wire x1="3.81" y1="34.29" x2="3.81" y2="8.89" width="0.127" layer="51"/>
<wire x1="3.81" y1="8.89" x2="1.27" y2="8.89" width="0.127" layer="51"/>
<wire x1="1.27" y1="8.89" x2="1.27" y2="34.29" width="0.127" layer="51"/>
<wire x1="49.53" y1="17.78" x2="52.07" y2="17.78" width="0.127" layer="51"/>
<wire x1="52.07" y1="17.78" x2="52.07" y2="38.1" width="0.127" layer="51"/>
<wire x1="52.07" y1="38.1" x2="49.53" y2="38.1" width="0.127" layer="51"/>
<wire x1="49.53" y1="38.1" x2="49.53" y2="17.78" width="0.127" layer="51"/>
<wire x1="52.07" y1="40.64" x2="49.53" y2="40.64" width="0.127" layer="51"/>
<wire x1="49.53" y1="40.64" x2="49.53" y2="55.88" width="0.127" layer="51"/>
<wire x1="49.53" y1="55.88" x2="52.07" y2="55.88" width="0.127" layer="51"/>
<wire x1="52.07" y1="55.88" x2="52.07" y2="40.64" width="0.127" layer="51"/>
<pad name="RES" x="50.8" y="24.13" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="3.3V" x="50.8" y="26.67" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="5V" x="50.8" y="29.21" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="GND@0" x="50.8" y="31.75" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="GND@1" x="50.8" y="34.29" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="VIN" x="50.8" y="36.83" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="A0" x="50.8" y="41.91" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="A1" x="50.8" y="44.45" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="A2" x="50.8" y="46.99" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="A3" x="50.8" y="49.53" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="A4" x="50.8" y="52.07" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="A5" x="50.8" y="54.61" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="RX" x="2.54" y="54.61" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="TX" x="2.54" y="52.07" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D2" x="2.54" y="49.53" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D3" x="2.54" y="46.99" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D4" x="2.54" y="44.45" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D5" x="2.54" y="41.91" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D6" x="2.54" y="39.37" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D7" x="2.54" y="36.83" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D8" x="2.54" y="33.02" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D9" x="2.54" y="30.48" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D10" x="2.54" y="27.94" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D11" x="2.54" y="25.4" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D12" x="2.54" y="22.86" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D13" x="2.54" y="20.32" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="GND@2" x="2.54" y="17.78" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="AREF" x="2.54" y="15.24" drill="1.016" diameter="1.8796" rot="R90"/>
<text x="49.4157" y="32.258" size="1.016" layer="21" font="vector" ratio="15" rot="R180">GND</text>
<text x="49.4157" y="34.798" size="1.016" layer="21" font="vector" ratio="15" rot="R180">GND</text>
<text x="49.4157" y="29.718" size="1.016" layer="21" font="vector" ratio="15" rot="R180">+5V</text>
<text x="49.4157" y="24.638" size="1.016" layer="21" font="vector" ratio="15" rot="R180">RST</text>
<text x="49.4157" y="37.338" size="1.016" layer="21" font="vector" ratio="15" rot="R180">VIN</text>
<text x="49.4157" y="27.178" size="1.016" layer="21" font="vector" ratio="15" rot="R180">+3.3V</text>
<text x="49.4157" y="42.418" size="1.016" layer="21" font="vector" ratio="15" rot="R180">0</text>
<text x="49.4157" y="44.958" size="1.016" layer="21" font="vector" ratio="15" rot="R180">1</text>
<text x="49.4157" y="47.498" size="1.016" layer="21" font="vector" ratio="15" rot="R180">2</text>
<text x="49.4157" y="50.038" size="1.016" layer="21" font="vector" ratio="15" rot="R180">3</text>
<text x="49.4157" y="52.578" size="1.016" layer="21" font="vector" ratio="15" rot="R180">4</text>
<text x="49.4157" y="55.118" size="1.016" layer="21" font="vector" ratio="15" rot="R180">5</text>
<text x="46.8757" y="52.197" size="1.016" layer="21" font="vector" ratio="15" rot="R270">Analog In</text>
<text x="3.81" y="17.272" size="1.016" layer="21" font="vector" ratio="15">GND</text>
<text x="3.81" y="19.812" size="1.016" layer="21" font="vector" ratio="15">13</text>
<text x="3.81" y="22.352" size="1.016" layer="21" font="vector" ratio="15">12</text>
<text x="3.81" y="24.892" size="1.016" layer="21" font="vector" ratio="15">11</text>
<text x="3.81" y="14.732" size="1.016" layer="21" font="vector" ratio="15">AREF</text>
<text x="3.81" y="27.432" size="1.016" layer="21" font="vector" ratio="15">10</text>
<text x="3.81" y="29.972" size="1.016" layer="21" font="vector" ratio="15">9</text>
<text x="3.81" y="32.512" size="1.016" layer="21" font="vector" ratio="15">8</text>
<text x="3.81" y="36.322" size="1.016" layer="21" font="vector" ratio="15">7</text>
<text x="3.81" y="38.862" size="1.016" layer="21" font="vector" ratio="15">6</text>
<text x="3.81" y="41.402" size="1.016" layer="21" font="vector" ratio="15">5</text>
<text x="3.81" y="43.942" size="1.016" layer="21" font="vector" ratio="15">4</text>
<text x="3.81" y="46.482" size="1.016" layer="21" font="vector" ratio="15">3</text>
<text x="3.81" y="49.022" size="1.016" layer="21" font="vector" ratio="15">2</text>
<text x="3.81" y="51.562" size="1.016" layer="21" font="vector" ratio="15">TX</text>
<text x="3.81" y="54.102" size="1.016" layer="21" font="vector" ratio="15">RX</text>
<pad name="SDA" x="2.54" y="12.7" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="SCL" x="2.54" y="10.16" drill="1.016" diameter="1.8796" rot="R90"/>
<text x="3.81" y="12.192" size="1.016" layer="21" font="vector" ratio="15">SDA</text>
<text x="3.81" y="9.652" size="1.016" layer="21" font="vector" ratio="15">SCL</text>
<pad name="IOREF" x="50.8" y="21.59" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="NC" x="50.8" y="19.05" drill="1.016" diameter="1.8796" rot="R90"/>
<text x="49.4157" y="22.098" size="1.016" layer="21" font="vector" ratio="15" rot="R180">IOREF</text>
<wire x1="22.225" y1="53.34" x2="21.59" y2="53.975" width="0.254" layer="51"/>
<wire x1="21.59" y1="53.975" x2="21.59" y2="57.785" width="0.254" layer="51"/>
<wire x1="21.59" y1="57.785" x2="22.225" y2="58.42" width="0.254" layer="51"/>
<wire x1="22.225" y1="58.42" x2="28.575" y2="58.42" width="0.254" layer="51"/>
<wire x1="28.575" y1="58.42" x2="29.21" y2="57.785" width="0.254" layer="51"/>
<wire x1="29.21" y1="57.785" x2="29.21" y2="53.975" width="0.254" layer="51"/>
<wire x1="29.21" y1="53.975" x2="28.575" y2="53.34" width="0.254" layer="51"/>
<wire x1="28.575" y1="53.34" x2="22.225" y2="53.34" width="0.254" layer="51"/>
<text x="27.305" y="52.451" size="0.508" layer="51" font="vector" ratio="15">RST</text>
<text x="24.892" y="55.626" size="0.508" layer="51" font="vector" ratio="15">ISP</text>
<wire x1="23.495" y1="52.832" x2="22.225" y2="52.832" width="0.2032" layer="51"/>
</package>
<package name="UNO_R3_SHIELD_NOLABELS">
<wire x1="2.54" y1="0" x2="9.5" y2="0" width="0.254" layer="51"/>
<wire x1="9.5" y1="0" x2="21.7" y2="0" width="0.254" layer="51"/>
<wire x1="21.7" y1="0" x2="50.8" y2="0" width="0.254" layer="51"/>
<wire x1="50.8" y1="0" x2="53.34" y2="2.54" width="0.254" layer="51"/>
<wire x1="53.34" y1="57.15" x2="50.8" y2="57.15" width="0.254" layer="51"/>
<wire x1="50.8" y1="57.15" x2="48.26" y2="59.69" width="0.254" layer="51"/>
<wire x1="0" y1="55.88" x2="0" y2="2.54" width="0.254" layer="51"/>
<wire x1="0" y1="2.54" x2="2.54" y2="0" width="0.254" layer="51"/>
<wire x1="48.26" y1="59.69" x2="15.24" y2="59.69" width="0.254" layer="51"/>
<wire x1="15.24" y1="59.69" x2="12.7" y2="57.15" width="0.254" layer="51"/>
<wire x1="12.7" y1="57.15" x2="1.27" y2="57.15" width="0.254" layer="51"/>
<wire x1="1.27" y1="57.15" x2="0" y2="55.88" width="0.254" layer="51"/>
<wire x1="53.34" y1="2.54" x2="53.34" y2="57.15" width="0.254" layer="51"/>
<wire x1="9.5" y1="-15.5" x2="21.7" y2="-15.5" width="0.254" layer="51"/>
<wire x1="40.2" y1="-10.3" x2="49.2" y2="-10.3" width="0.254" layer="51"/>
<wire x1="9.5" y1="-15.5" x2="9.5" y2="0" width="0.254" layer="51"/>
<wire x1="21.7" y1="-15.5" x2="21.7" y2="0" width="0.254" layer="51"/>
<wire x1="40.2" y1="-10.3" x2="40.2" y2="-0.1" width="0.254" layer="51"/>
<wire x1="49.2" y1="-10.3" x2="49.2" y2="-0.1" width="0.254" layer="51"/>
<wire x1="1.27" y1="55.88" x2="3.81" y2="55.88" width="0.127" layer="51"/>
<wire x1="3.81" y1="55.88" x2="3.81" y2="35.56" width="0.127" layer="51"/>
<wire x1="3.81" y1="35.56" x2="1.27" y2="35.56" width="0.127" layer="51"/>
<wire x1="1.27" y1="35.56" x2="1.27" y2="55.88" width="0.127" layer="51"/>
<wire x1="1.27" y1="34.29" x2="3.81" y2="34.29" width="0.127" layer="51"/>
<wire x1="3.81" y1="34.29" x2="3.81" y2="8.89" width="0.127" layer="51"/>
<wire x1="3.81" y1="8.89" x2="1.27" y2="8.89" width="0.127" layer="51"/>
<wire x1="1.27" y1="8.89" x2="1.27" y2="34.29" width="0.127" layer="51"/>
<wire x1="49.53" y1="17.78" x2="52.07" y2="17.78" width="0.127" layer="51"/>
<wire x1="52.07" y1="17.78" x2="52.07" y2="38.1" width="0.127" layer="51"/>
<wire x1="52.07" y1="38.1" x2="49.53" y2="38.1" width="0.127" layer="51"/>
<wire x1="52.07" y1="40.64" x2="49.53" y2="40.64" width="0.127" layer="51"/>
<wire x1="49.53" y1="40.64" x2="49.53" y2="55.88" width="0.127" layer="51"/>
<wire x1="49.53" y1="55.88" x2="52.07" y2="55.88" width="0.127" layer="51"/>
<wire x1="52.07" y1="55.88" x2="52.07" y2="40.64" width="0.127" layer="51"/>
<pad name="RES" x="50.8" y="24.13" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="3.3V" x="50.8" y="26.67" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="5V" x="50.8" y="29.21" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="GND@0" x="50.8" y="31.75" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="GND@1" x="50.8" y="34.29" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="VIN" x="50.8" y="36.83" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="A0" x="50.8" y="41.91" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="A1" x="50.8" y="44.45" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="A2" x="50.8" y="46.99" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="A3" x="50.8" y="49.53" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="A4" x="50.8" y="52.07" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="A5" x="50.8" y="54.61" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="RX" x="2.54" y="54.61" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="TX" x="2.54" y="52.07" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D2" x="2.54" y="49.53" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D3" x="2.54" y="46.99" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D4" x="2.54" y="44.45" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D5" x="2.54" y="41.91" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D6" x="2.54" y="39.37" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D7" x="2.54" y="36.83" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D8" x="2.54" y="33.02" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D9" x="2.54" y="30.48" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D10" x="2.54" y="27.94" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D11" x="2.54" y="25.4" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D12" x="2.54" y="22.86" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D13" x="2.54" y="20.32" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="GND@2" x="2.54" y="17.78" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="AREF" x="2.54" y="15.24" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="SDA" x="2.54" y="12.7" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="SCL" x="2.54" y="10.16" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="IOREF" x="50.8" y="21.59" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="NC" x="50.8" y="19.05" drill="1.016" diameter="1.8796" rot="R90"/>
<wire x1="22.225" y1="53.34" x2="21.59" y2="53.975" width="0.254" layer="51"/>
<wire x1="21.59" y1="53.975" x2="21.59" y2="57.785" width="0.254" layer="51"/>
<wire x1="21.59" y1="57.785" x2="22.225" y2="58.42" width="0.254" layer="51"/>
<wire x1="22.225" y1="58.42" x2="28.575" y2="58.42" width="0.254" layer="51"/>
<wire x1="28.575" y1="58.42" x2="29.21" y2="57.785" width="0.254" layer="51"/>
<wire x1="29.21" y1="57.785" x2="29.21" y2="53.975" width="0.254" layer="51"/>
<wire x1="29.21" y1="53.975" x2="28.575" y2="53.34" width="0.254" layer="51"/>
<wire x1="28.575" y1="53.34" x2="22.225" y2="53.34" width="0.254" layer="51"/>
<text x="27.305" y="52.451" size="0.508" layer="51" font="vector" ratio="15">RST</text>
<text x="24.892" y="55.626" size="0.508" layer="51" ratio="15">ISP</text>
<wire x1="23.495" y1="52.832" x2="22.225" y2="52.832" width="0.2032" layer="51"/>
<wire x1="49.53" y1="38.1" x2="49.53" y2="17.78" width="0.127" layer="51"/>
</package>
<package name="UNO_R3_SHIELD_LOCK">
<description>Uno R3 Compatible Board Layout</description>
<wire x1="2.54" y1="0" x2="9.5" y2="0" width="0.254" layer="51"/>
<wire x1="9.5" y1="0" x2="21.7" y2="0" width="0.254" layer="51"/>
<wire x1="21.7" y1="0" x2="50.8" y2="0" width="0.254" layer="51"/>
<wire x1="50.8" y1="0" x2="53.34" y2="2.54" width="0.254" layer="51"/>
<wire x1="53.34" y1="57.15" x2="50.8" y2="57.15" width="0.254" layer="51"/>
<wire x1="50.8" y1="57.15" x2="48.26" y2="59.69" width="0.254" layer="51"/>
<wire x1="0" y1="55.88" x2="0" y2="2.54" width="0.254" layer="51"/>
<wire x1="0" y1="2.54" x2="2.54" y2="0" width="0.254" layer="51"/>
<wire x1="48.26" y1="59.69" x2="15.24" y2="59.69" width="0.254" layer="51"/>
<wire x1="15.24" y1="59.69" x2="12.7" y2="57.15" width="0.254" layer="51"/>
<wire x1="12.7" y1="57.15" x2="1.27" y2="57.15" width="0.254" layer="51"/>
<wire x1="1.27" y1="57.15" x2="0" y2="55.88" width="0.254" layer="51"/>
<wire x1="53.34" y1="2.54" x2="53.34" y2="57.15" width="0.254" layer="51"/>
<wire x1="9.5" y1="-15.5" x2="21.7" y2="-15.5" width="0.254" layer="51"/>
<wire x1="40.2" y1="-10.3" x2="49.2" y2="-10.3" width="0.254" layer="51"/>
<wire x1="9.5" y1="-15.5" x2="9.5" y2="0" width="0.254" layer="51"/>
<wire x1="21.7" y1="-15.5" x2="21.7" y2="0" width="0.254" layer="51"/>
<wire x1="40.2" y1="-10.3" x2="40.2" y2="-0.1" width="0.254" layer="51"/>
<wire x1="49.2" y1="-10.3" x2="49.2" y2="-0.1" width="0.254" layer="51"/>
<wire x1="1.27" y1="55.88" x2="3.81" y2="55.88" width="0.127" layer="51"/>
<wire x1="3.81" y1="55.88" x2="3.81" y2="35.56" width="0.127" layer="51"/>
<wire x1="3.81" y1="35.56" x2="1.27" y2="35.56" width="0.127" layer="51"/>
<wire x1="1.27" y1="35.56" x2="1.27" y2="55.88" width="0.127" layer="51"/>
<wire x1="1.27" y1="34.29" x2="3.81" y2="34.29" width="0.127" layer="51"/>
<wire x1="3.81" y1="34.29" x2="3.81" y2="8.89" width="0.127" layer="51"/>
<wire x1="3.81" y1="8.89" x2="1.27" y2="8.89" width="0.127" layer="51"/>
<wire x1="1.27" y1="8.89" x2="1.27" y2="34.29" width="0.127" layer="51"/>
<wire x1="49.53" y1="17.78" x2="52.07" y2="17.78" width="0.127" layer="51"/>
<wire x1="52.07" y1="17.78" x2="52.07" y2="38.1" width="0.127" layer="51"/>
<wire x1="52.07" y1="38.1" x2="49.53" y2="38.1" width="0.127" layer="51"/>
<wire x1="49.53" y1="38.1" x2="49.53" y2="17.78" width="0.127" layer="51"/>
<wire x1="52.07" y1="40.64" x2="49.53" y2="40.64" width="0.127" layer="51"/>
<wire x1="49.53" y1="40.64" x2="49.53" y2="55.88" width="0.127" layer="51"/>
<wire x1="49.53" y1="55.88" x2="52.07" y2="55.88" width="0.127" layer="51"/>
<wire x1="52.07" y1="55.88" x2="52.07" y2="40.64" width="0.127" layer="51"/>
<pad name="RES" x="51.054" y="24.13" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="3.3V" x="50.8" y="26.67" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="5V" x="51.054" y="29.21" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="GND@0" x="50.8" y="31.75" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="GND@1" x="51.054" y="34.29" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="VIN" x="50.8" y="36.83" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="A0" x="51.054" y="41.91" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="A1" x="50.8" y="44.45" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="A2" x="51.054" y="46.99" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="A3" x="50.8" y="49.53" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="A4" x="51.054" y="52.07" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="A5" x="50.8" y="54.61" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="RX" x="2.54" y="54.61" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="TX" x="2.286" y="52.07" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D2" x="2.54" y="49.53" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D3" x="2.286" y="46.99" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D4" x="2.54" y="44.45" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D5" x="2.286" y="41.91" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D6" x="2.54" y="39.37" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D7" x="2.286" y="36.83" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D8" x="2.54" y="33.02" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D9" x="2.286" y="30.48" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D10" x="2.54" y="27.94" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D11" x="2.286" y="25.4" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D12" x="2.54" y="22.86" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D13" x="2.286" y="20.32" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="GND@2" x="2.54" y="17.78" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="AREF" x="2.286" y="15.24" drill="1.016" diameter="1.8796" rot="R90"/>
<text x="49.4157" y="32.258" size="1.016" layer="21" font="vector" ratio="15" rot="R180">GND</text>
<text x="49.4157" y="34.798" size="1.016" layer="21" font="vector" ratio="15" rot="R180">GND</text>
<text x="49.4157" y="29.718" size="1.016" layer="21" font="vector" ratio="15" rot="R180">+5V</text>
<text x="49.4157" y="24.638" size="1.016" layer="21" font="vector" ratio="15" rot="R180">RST</text>
<text x="49.4157" y="37.338" size="1.016" layer="21" font="vector" ratio="15" rot="R180">VIN</text>
<text x="49.4157" y="27.178" size="1.016" layer="21" font="vector" ratio="15" rot="R180">+3.3V</text>
<text x="49.4157" y="42.418" size="1.016" layer="21" font="vector" ratio="15" rot="R180">0</text>
<text x="49.4157" y="44.958" size="1.016" layer="21" font="vector" ratio="15" rot="R180">1</text>
<text x="49.4157" y="47.498" size="1.016" layer="21" font="vector" ratio="15" rot="R180">2</text>
<text x="49.4157" y="50.038" size="1.016" layer="21" font="vector" ratio="15" rot="R180">3</text>
<text x="49.4157" y="52.578" size="1.016" layer="21" font="vector" ratio="15" rot="R180">4</text>
<text x="49.4157" y="55.118" size="1.016" layer="21" font="vector" ratio="15" rot="R180">5</text>
<text x="46.8757" y="52.197" size="1.016" layer="21" font="vector" ratio="15" rot="R270">Analog In</text>
<text x="3.81" y="17.272" size="1.016" layer="21" font="vector" ratio="15">GND</text>
<text x="3.81" y="19.812" size="1.016" layer="21" font="vector" ratio="15">13</text>
<text x="3.81" y="22.352" size="1.016" layer="21" font="vector" ratio="15">12</text>
<text x="3.81" y="24.892" size="1.016" layer="21" font="vector" ratio="15">11</text>
<text x="3.81" y="14.732" size="1.016" layer="21" font="vector" ratio="15">AREF</text>
<text x="3.81" y="27.432" size="1.016" layer="21" font="vector" ratio="15">10</text>
<text x="3.81" y="29.972" size="1.016" layer="21" font="vector" ratio="15">9</text>
<text x="3.81" y="32.512" size="1.016" layer="21" font="vector" ratio="15">8</text>
<text x="3.81" y="36.322" size="1.016" layer="21" font="vector" ratio="15">7</text>
<text x="3.81" y="38.862" size="1.016" layer="21" font="vector" ratio="15">6</text>
<text x="3.81" y="41.402" size="1.016" layer="21" font="vector" ratio="15">5</text>
<text x="3.81" y="43.942" size="1.016" layer="21" font="vector" ratio="15">4</text>
<text x="3.81" y="46.482" size="1.016" layer="21" font="vector" ratio="15">3</text>
<text x="3.81" y="49.022" size="1.016" layer="21" font="vector" ratio="15">2</text>
<text x="3.81" y="51.562" size="1.016" layer="21" font="vector" ratio="15">TX</text>
<text x="3.81" y="54.102" size="1.016" layer="21" font="vector" ratio="15">RX</text>
<pad name="SDA" x="2.54" y="12.7" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="SCL" x="2.54" y="10.16" drill="1.016" diameter="1.8796" rot="R90"/>
<text x="3.81" y="12.192" size="1.016" layer="21" font="vector" ratio="15">SDA</text>
<text x="3.81" y="9.652" size="1.016" layer="21" font="vector" ratio="15">SCL</text>
<pad name="IOREF" x="50.8" y="21.59" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="NC" x="51.054" y="19.05" drill="1.016" diameter="1.8796" rot="R90"/>
<text x="49.4157" y="22.098" size="1.016" layer="21" font="vector" ratio="15" rot="R180">IOREF</text>
<wire x1="22.225" y1="53.34" x2="21.59" y2="53.975" width="0.254" layer="51"/>
<wire x1="21.59" y1="53.975" x2="21.59" y2="57.785" width="0.254" layer="51"/>
<wire x1="21.59" y1="57.785" x2="22.225" y2="58.42" width="0.254" layer="51"/>
<wire x1="22.225" y1="58.42" x2="28.575" y2="58.42" width="0.254" layer="51"/>
<wire x1="28.575" y1="58.42" x2="29.21" y2="57.785" width="0.254" layer="51"/>
<wire x1="29.21" y1="57.785" x2="29.21" y2="53.975" width="0.254" layer="51"/>
<wire x1="29.21" y1="53.975" x2="28.575" y2="53.34" width="0.254" layer="51"/>
<wire x1="28.575" y1="53.34" x2="22.225" y2="53.34" width="0.254" layer="51"/>
<text x="27.305" y="52.451" size="0.508" layer="51" font="vector" ratio="15">RST</text>
<text x="24.892" y="55.626" size="0.508" layer="51" font="vector" ratio="15">ISP</text>
<wire x1="23.495" y1="52.832" x2="22.225" y2="52.832" width="0.2032" layer="51"/>
</package>
<package name="UNO_R3_SHIELD_NOLABELS_LOCK">
<description>Uno R3 Compatible Board Layout</description>
<wire x1="2.54" y1="0" x2="9.5" y2="0" width="0.254" layer="51"/>
<wire x1="9.5" y1="0" x2="21.7" y2="0" width="0.254" layer="51"/>
<wire x1="21.7" y1="0" x2="50.8" y2="0" width="0.254" layer="51"/>
<wire x1="50.8" y1="0" x2="53.34" y2="2.54" width="0.254" layer="51"/>
<wire x1="53.34" y1="57.15" x2="50.8" y2="57.15" width="0.254" layer="51"/>
<wire x1="50.8" y1="57.15" x2="48.26" y2="59.69" width="0.254" layer="51"/>
<wire x1="0" y1="55.88" x2="0" y2="2.54" width="0.254" layer="51"/>
<wire x1="0" y1="2.54" x2="2.54" y2="0" width="0.254" layer="51"/>
<wire x1="48.26" y1="59.69" x2="15.24" y2="59.69" width="0.254" layer="51"/>
<wire x1="15.24" y1="59.69" x2="12.7" y2="57.15" width="0.254" layer="51"/>
<wire x1="12.7" y1="57.15" x2="1.27" y2="57.15" width="0.254" layer="51"/>
<wire x1="1.27" y1="57.15" x2="0" y2="55.88" width="0.254" layer="51"/>
<wire x1="53.34" y1="2.54" x2="53.34" y2="57.15" width="0.254" layer="51"/>
<wire x1="9.5" y1="-15.5" x2="21.7" y2="-15.5" width="0.254" layer="51"/>
<wire x1="40.2" y1="-10.3" x2="49.2" y2="-10.3" width="0.254" layer="51"/>
<wire x1="9.5" y1="-15.5" x2="9.5" y2="0" width="0.254" layer="51"/>
<wire x1="21.7" y1="-15.5" x2="21.7" y2="0" width="0.254" layer="51"/>
<wire x1="40.2" y1="-10.3" x2="40.2" y2="-0.1" width="0.254" layer="51"/>
<wire x1="49.2" y1="-10.3" x2="49.2" y2="-0.1" width="0.254" layer="51"/>
<wire x1="1.27" y1="55.88" x2="3.81" y2="55.88" width="0.127" layer="51"/>
<wire x1="3.81" y1="55.88" x2="3.81" y2="35.56" width="0.127" layer="51"/>
<wire x1="3.81" y1="35.56" x2="1.27" y2="35.56" width="0.127" layer="51"/>
<wire x1="1.27" y1="35.56" x2="1.27" y2="55.88" width="0.127" layer="51"/>
<wire x1="1.27" y1="34.29" x2="3.81" y2="34.29" width="0.127" layer="51"/>
<wire x1="3.81" y1="34.29" x2="3.81" y2="8.89" width="0.127" layer="51"/>
<wire x1="3.81" y1="8.89" x2="1.27" y2="8.89" width="0.127" layer="51"/>
<wire x1="1.27" y1="8.89" x2="1.27" y2="34.29" width="0.127" layer="51"/>
<wire x1="49.53" y1="17.78" x2="52.07" y2="17.78" width="0.127" layer="51"/>
<wire x1="52.07" y1="17.78" x2="52.07" y2="38.1" width="0.127" layer="51"/>
<wire x1="52.07" y1="38.1" x2="49.53" y2="38.1" width="0.127" layer="51"/>
<wire x1="49.53" y1="38.1" x2="49.53" y2="17.78" width="0.127" layer="51"/>
<wire x1="52.07" y1="40.64" x2="49.53" y2="40.64" width="0.127" layer="51"/>
<wire x1="49.53" y1="40.64" x2="49.53" y2="55.88" width="0.127" layer="51"/>
<wire x1="49.53" y1="55.88" x2="52.07" y2="55.88" width="0.127" layer="51"/>
<wire x1="52.07" y1="55.88" x2="52.07" y2="40.64" width="0.127" layer="51"/>
<pad name="RES" x="51.054" y="24.13" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="3.3V" x="50.8" y="26.67" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="5V" x="51.054" y="29.21" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="GND@0" x="50.8" y="31.75" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="GND@1" x="51.054" y="34.29" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="VIN" x="50.8" y="36.83" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="A0" x="51.054" y="41.91" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="A1" x="50.8" y="44.45" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="A2" x="51.054" y="46.99" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="A3" x="50.8" y="49.53" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="A4" x="51.054" y="52.07" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="A5" x="50.8" y="54.61" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="RX" x="2.54" y="54.61" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="TX" x="2.286" y="52.07" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D2" x="2.54" y="49.53" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D3" x="2.286" y="46.99" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D4" x="2.54" y="44.45" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D5" x="2.286" y="41.91" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D6" x="2.54" y="39.37" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D7" x="2.286" y="36.83" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D8" x="2.54" y="33.02" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D9" x="2.286" y="30.48" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D10" x="2.54" y="27.94" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D11" x="2.286" y="25.4" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D12" x="2.54" y="22.86" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="D13" x="2.286" y="20.32" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="GND@2" x="2.54" y="17.78" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="AREF" x="2.286" y="15.24" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="SDA" x="2.54" y="12.7" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="SCL" x="2.54" y="10.16" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="IOREF" x="50.8" y="21.59" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="NC" x="51.054" y="19.05" drill="1.016" diameter="1.8796" rot="R90"/>
<wire x1="22.225" y1="53.34" x2="21.59" y2="53.975" width="0.254" layer="51"/>
<wire x1="21.59" y1="53.975" x2="21.59" y2="57.785" width="0.254" layer="51"/>
<wire x1="21.59" y1="57.785" x2="22.225" y2="58.42" width="0.254" layer="51"/>
<wire x1="22.225" y1="58.42" x2="28.575" y2="58.42" width="0.254" layer="51"/>
<wire x1="28.575" y1="58.42" x2="29.21" y2="57.785" width="0.254" layer="51"/>
<wire x1="29.21" y1="57.785" x2="29.21" y2="53.975" width="0.254" layer="51"/>
<wire x1="29.21" y1="53.975" x2="28.575" y2="53.34" width="0.254" layer="51"/>
<wire x1="28.575" y1="53.34" x2="22.225" y2="53.34" width="0.254" layer="51"/>
<text x="27.305" y="52.451" size="0.508" layer="51" font="vector" ratio="15">RST</text>
<text x="24.892" y="55.626" size="0.508" layer="51" font="vector" ratio="15">ISP</text>
<wire x1="23.495" y1="52.832" x2="22.225" y2="52.832" width="0.2032" layer="51"/>
</package>
</packages>
<symbols>
<symbol name="ARDUINO_R3_SHIELD">
<wire x1="-10.16" y1="-25.4" x2="-10.16" y2="20.32" width="0.254" layer="94"/>
<wire x1="-10.16" y1="20.32" x2="10.16" y2="20.32" width="0.254" layer="94"/>
<wire x1="10.16" y1="20.32" x2="10.16" y2="-25.4" width="0.254" layer="94"/>
<wire x1="10.16" y1="-25.4" x2="-10.16" y2="-25.4" width="0.254" layer="94"/>
<text x="-9.652" y="21.082" size="1.778" layer="95">&gt;Name</text>
<text x="-6.35" y="-27.94" size="1.778" layer="96">&gt;Value</text>
<pin name="RX" x="12.7" y="17.78" visible="pin" length="short" rot="R180"/>
<pin name="TX" x="12.7" y="15.24" visible="pin" length="short" rot="R180"/>
<pin name="D2" x="12.7" y="10.16" visible="pin" length="short" rot="R180"/>
<pin name="*D3" x="12.7" y="7.62" visible="pin" length="short" rot="R180"/>
<pin name="D4" x="12.7" y="5.08" visible="pin" length="short" rot="R180"/>
<pin name="*D5" x="12.7" y="2.54" visible="pin" length="short" rot="R180"/>
<pin name="*D6" x="12.7" y="0" visible="pin" length="short" rot="R180"/>
<pin name="D7" x="12.7" y="-2.54" visible="pin" length="short" rot="R180"/>
<pin name="D8" x="12.7" y="-5.08" visible="pin" length="short" rot="R180"/>
<pin name="*D9" x="12.7" y="-7.62" visible="pin" length="short" rot="R180"/>
<pin name="*D10" x="12.7" y="-10.16" visible="pin" length="short" rot="R180"/>
<pin name="*D11" x="12.7" y="-12.7" visible="pin" length="short" rot="R180"/>
<pin name="D12" x="12.7" y="-15.24" visible="pin" length="short" rot="R180"/>
<pin name="D13" x="12.7" y="-17.78" visible="pin" length="short" rot="R180"/>
<pin name="A0" x="-12.7" y="17.78" visible="pin" length="short"/>
<pin name="A1" x="-12.7" y="15.24" visible="pin" length="short"/>
<pin name="A2" x="-12.7" y="12.7" visible="pin" length="short"/>
<pin name="A3" x="-12.7" y="10.16" visible="pin" length="short"/>
<pin name="A4" x="-12.7" y="7.62" visible="pin" length="short"/>
<pin name="A5" x="-12.7" y="5.08" visible="pin" length="short"/>
<pin name="VIN" x="-12.7" y="-7.62" visible="pin" length="short"/>
<pin name="RES" x="-12.7" y="-5.08" visible="pin" length="short"/>
<pin name="5V" x="-12.7" y="-10.16" visible="pin" length="short"/>
<pin name="AREF" x="-12.7" y="-15.24" visible="pin" length="short"/>
<pin name="GND@2" x="-12.7" y="-17.78" visible="pin" length="short"/>
<pin name="GND@1" x="-12.7" y="-20.32" visible="pin" length="short"/>
<pin name="GND@0" x="-12.7" y="-22.86" visible="pin" length="short"/>
<pin name="3.3V" x="-12.7" y="-12.7" visible="pin" length="short"/>
<pin name="IOREF" x="-12.7" y="-2.54" visible="pin" length="short"/>
<pin name="SDA" x="12.7" y="-20.32" visible="pin" length="short" rot="R180"/>
<pin name="SCL" x="12.7" y="-22.86" visible="pin" length="short" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="ARDUINO_R3_SHIELD" prefix="J">
<description>Shield form compatible with the Arduino Uno R3.</description>
<gates>
<gate name="G$1" symbol="ARDUINO_R3_SHIELD" x="0" y="0"/>
</gates>
<devices>
<device name="" package="UNO_R3_SHIELD">
<connects>
<connect gate="G$1" pin="*D10" pad="D10"/>
<connect gate="G$1" pin="*D11" pad="D11"/>
<connect gate="G$1" pin="*D3" pad="D3"/>
<connect gate="G$1" pin="*D5" pad="D5"/>
<connect gate="G$1" pin="*D6" pad="D6"/>
<connect gate="G$1" pin="*D9" pad="D9"/>
<connect gate="G$1" pin="3.3V" pad="3.3V"/>
<connect gate="G$1" pin="5V" pad="5V"/>
<connect gate="G$1" pin="A0" pad="A0"/>
<connect gate="G$1" pin="A1" pad="A1"/>
<connect gate="G$1" pin="A2" pad="A2"/>
<connect gate="G$1" pin="A3" pad="A3"/>
<connect gate="G$1" pin="A4" pad="A4"/>
<connect gate="G$1" pin="A5" pad="A5"/>
<connect gate="G$1" pin="AREF" pad="AREF"/>
<connect gate="G$1" pin="D12" pad="D12"/>
<connect gate="G$1" pin="D13" pad="D13"/>
<connect gate="G$1" pin="D2" pad="D2"/>
<connect gate="G$1" pin="D4" pad="D4"/>
<connect gate="G$1" pin="D7" pad="D7"/>
<connect gate="G$1" pin="D8" pad="D8"/>
<connect gate="G$1" pin="GND@0" pad="GND@0"/>
<connect gate="G$1" pin="GND@1" pad="GND@1"/>
<connect gate="G$1" pin="GND@2" pad="GND@2"/>
<connect gate="G$1" pin="IOREF" pad="IOREF"/>
<connect gate="G$1" pin="RES" pad="RES"/>
<connect gate="G$1" pin="RX" pad="RX"/>
<connect gate="G$1" pin="SCL" pad="SCL"/>
<connect gate="G$1" pin="SDA" pad="SDA"/>
<connect gate="G$1" pin="TX" pad="TX"/>
<connect gate="G$1" pin="VIN" pad="VIN"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="NOLABELS" package="UNO_R3_SHIELD_NOLABELS">
<connects>
<connect gate="G$1" pin="*D10" pad="D10"/>
<connect gate="G$1" pin="*D11" pad="D11"/>
<connect gate="G$1" pin="*D3" pad="D3"/>
<connect gate="G$1" pin="*D5" pad="D5"/>
<connect gate="G$1" pin="*D6" pad="D6"/>
<connect gate="G$1" pin="*D9" pad="D9"/>
<connect gate="G$1" pin="3.3V" pad="3.3V"/>
<connect gate="G$1" pin="5V" pad="5V"/>
<connect gate="G$1" pin="A0" pad="A0"/>
<connect gate="G$1" pin="A1" pad="A1"/>
<connect gate="G$1" pin="A2" pad="A2"/>
<connect gate="G$1" pin="A3" pad="A3"/>
<connect gate="G$1" pin="A4" pad="A4"/>
<connect gate="G$1" pin="A5" pad="A5"/>
<connect gate="G$1" pin="AREF" pad="AREF"/>
<connect gate="G$1" pin="D12" pad="D12"/>
<connect gate="G$1" pin="D13" pad="D13"/>
<connect gate="G$1" pin="D2" pad="D2"/>
<connect gate="G$1" pin="D4" pad="D4"/>
<connect gate="G$1" pin="D7" pad="D7"/>
<connect gate="G$1" pin="D8" pad="D8"/>
<connect gate="G$1" pin="GND@0" pad="GND@0"/>
<connect gate="G$1" pin="GND@1" pad="GND@1"/>
<connect gate="G$1" pin="GND@2" pad="GND@2"/>
<connect gate="G$1" pin="IOREF" pad="IOREF"/>
<connect gate="G$1" pin="RES" pad="RES"/>
<connect gate="G$1" pin="RX" pad="RX"/>
<connect gate="G$1" pin="SCL" pad="SCL"/>
<connect gate="G$1" pin="SDA" pad="SDA"/>
<connect gate="G$1" pin="TX" pad="TX"/>
<connect gate="G$1" pin="VIN" pad="VIN"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="UNO_R3_SHIELD_LOCK" package="UNO_R3_SHIELD_LOCK">
<connects>
<connect gate="G$1" pin="*D10" pad="D10"/>
<connect gate="G$1" pin="*D11" pad="D11"/>
<connect gate="G$1" pin="*D3" pad="D3"/>
<connect gate="G$1" pin="*D5" pad="D5"/>
<connect gate="G$1" pin="*D6" pad="D6"/>
<connect gate="G$1" pin="*D9" pad="D9"/>
<connect gate="G$1" pin="3.3V" pad="3.3V"/>
<connect gate="G$1" pin="5V" pad="5V"/>
<connect gate="G$1" pin="A0" pad="A0"/>
<connect gate="G$1" pin="A1" pad="A1"/>
<connect gate="G$1" pin="A2" pad="A2"/>
<connect gate="G$1" pin="A3" pad="A3"/>
<connect gate="G$1" pin="A4" pad="A4"/>
<connect gate="G$1" pin="A5" pad="A5"/>
<connect gate="G$1" pin="AREF" pad="AREF"/>
<connect gate="G$1" pin="D12" pad="D12"/>
<connect gate="G$1" pin="D13" pad="D13"/>
<connect gate="G$1" pin="D2" pad="D2"/>
<connect gate="G$1" pin="D4" pad="D4"/>
<connect gate="G$1" pin="D7" pad="D7"/>
<connect gate="G$1" pin="D8" pad="D8"/>
<connect gate="G$1" pin="GND@0" pad="GND@0"/>
<connect gate="G$1" pin="GND@1" pad="GND@1"/>
<connect gate="G$1" pin="GND@2" pad="GND@2"/>
<connect gate="G$1" pin="IOREF" pad="IOREF"/>
<connect gate="G$1" pin="RES" pad="RES"/>
<connect gate="G$1" pin="RX" pad="RX"/>
<connect gate="G$1" pin="SCL" pad="SCL"/>
<connect gate="G$1" pin="SDA" pad="SDA"/>
<connect gate="G$1" pin="TX" pad="TX"/>
<connect gate="G$1" pin="VIN" pad="VIN"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="UNO_R3_SHIELD_NOLABELS_LOCK" package="UNO_R3_SHIELD_NOLABELS_LOCK">
<connects>
<connect gate="G$1" pin="*D10" pad="D10"/>
<connect gate="G$1" pin="*D11" pad="D11"/>
<connect gate="G$1" pin="*D3" pad="D3"/>
<connect gate="G$1" pin="*D5" pad="D5"/>
<connect gate="G$1" pin="*D6" pad="D6"/>
<connect gate="G$1" pin="*D9" pad="D9"/>
<connect gate="G$1" pin="3.3V" pad="3.3V"/>
<connect gate="G$1" pin="5V" pad="5V"/>
<connect gate="G$1" pin="A0" pad="A0"/>
<connect gate="G$1" pin="A1" pad="A1"/>
<connect gate="G$1" pin="A2" pad="A2"/>
<connect gate="G$1" pin="A3" pad="A3"/>
<connect gate="G$1" pin="A4" pad="A4"/>
<connect gate="G$1" pin="A5" pad="A5"/>
<connect gate="G$1" pin="AREF" pad="AREF"/>
<connect gate="G$1" pin="D12" pad="D12"/>
<connect gate="G$1" pin="D13" pad="D13"/>
<connect gate="G$1" pin="D2" pad="D2"/>
<connect gate="G$1" pin="D4" pad="D4"/>
<connect gate="G$1" pin="D7" pad="D7"/>
<connect gate="G$1" pin="D8" pad="D8"/>
<connect gate="G$1" pin="GND@0" pad="GND@0"/>
<connect gate="G$1" pin="GND@1" pad="GND@1"/>
<connect gate="G$1" pin="GND@2" pad="GND@2"/>
<connect gate="G$1" pin="IOREF" pad="IOREF"/>
<connect gate="G$1" pin="RES" pad="RES"/>
<connect gate="G$1" pin="RX" pad="RX"/>
<connect gate="G$1" pin="SCL" pad="SCL"/>
<connect gate="G$1" pin="SDA" pad="SDA"/>
<connect gate="G$1" pin="TX" pad="TX"/>
<connect gate="G$1" pin="VIN" pad="VIN"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="SparkFun-Resistors">
<description>&lt;h3&gt;SparkFun Electronics' preferred foot prints&lt;/h3&gt;
In this library you'll find resistors, capacitors, inductors, test points, jumper pads, etc.&lt;br&gt;&lt;br&gt;
We've spent an enormous amount of time creating and checking these footprints and parts, but it is the end user's responsibility to ensure correctness and suitablity for a given componet or application. If you enjoy using this library, please buy one of our products at www.sparkfun.com.
&lt;br&gt;&lt;br&gt;
&lt;b&gt;Licensing:&lt;/b&gt; Creative Commons ShareAlike 4.0 International - https://creativecommons.org/licenses/by-sa/4.0/ 
&lt;br&gt;&lt;br&gt;
You are welcome to use this library for commercial purposes. For attribution, we ask that when you begin to sell your device using our footprint, you email us with a link to the product being sold. We want bragging rights that we helped (in a very small part) to create your 8th world wonder. We would like the opportunity to feature your device on our homepage.</description>
<packages>
<package name="AXIAL-0.3">
<wire x1="-2.54" y1="0.762" x2="2.54" y2="0.762" width="0.2032" layer="21"/>
<wire x1="2.54" y1="0.762" x2="2.54" y2="0" width="0.2032" layer="21"/>
<wire x1="2.54" y1="0" x2="2.54" y2="-0.762" width="0.2032" layer="21"/>
<wire x1="2.54" y1="-0.762" x2="-2.54" y2="-0.762" width="0.2032" layer="21"/>
<wire x1="-2.54" y1="-0.762" x2="-2.54" y2="0" width="0.2032" layer="21"/>
<wire x1="-2.54" y1="0" x2="-2.54" y2="0.762" width="0.2032" layer="21"/>
<wire x1="2.54" y1="0" x2="2.794" y2="0" width="0.2032" layer="21"/>
<wire x1="-2.54" y1="0" x2="-2.794" y2="0" width="0.2032" layer="21"/>
<pad name="P$1" x="-3.81" y="0" drill="0.9" diameter="1.8796"/>
<pad name="P$2" x="3.81" y="0" drill="0.9" diameter="1.8796"/>
<text x="-2.54" y="1.27" size="0.4064" layer="25" font="vector">&gt;Name</text>
<text x="-2.032" y="-0.381" size="1.016" layer="21" font="vector" ratio="15">&gt;Value</text>
</package>
<package name="AXIAL-0.3EZ">
<description>This is the "EZ" version of the standard .3" spaced resistor package.&lt;br&gt;
It has a reduced top mask to make it harder to install upside-down.</description>
<wire x1="-2.54" y1="0.762" x2="2.54" y2="0.762" width="0.2032" layer="21"/>
<wire x1="2.54" y1="0.762" x2="2.54" y2="0" width="0.2032" layer="21"/>
<wire x1="2.54" y1="0" x2="2.54" y2="-0.762" width="0.2032" layer="21"/>
<wire x1="2.54" y1="-0.762" x2="-2.54" y2="-0.762" width="0.2032" layer="21"/>
<wire x1="-2.54" y1="-0.762" x2="-2.54" y2="0" width="0.2032" layer="21"/>
<wire x1="-2.54" y1="0" x2="-2.54" y2="0.762" width="0.2032" layer="21"/>
<wire x1="2.54" y1="0" x2="2.794" y2="0" width="0.2032" layer="21"/>
<wire x1="-2.54" y1="0" x2="-2.794" y2="0" width="0.2032" layer="21"/>
<pad name="P$1" x="-3.81" y="0" drill="0.9" diameter="1.8796" stop="no"/>
<pad name="P$2" x="3.81" y="0" drill="0.9" diameter="1.8796" stop="no"/>
<text x="-2.54" y="1.27" size="0.4064" layer="25" font="vector">&gt;Name</text>
<text x="-2.032" y="-0.381" size="1.016" layer="21" font="vector" ratio="15">&gt;Value</text>
<circle x="-3.81" y="0" radius="0.508" width="0" layer="29"/>
<circle x="3.81" y="0" radius="0.523634375" width="0" layer="29"/>
<circle x="-3.81" y="0" radius="1.02390625" width="0" layer="30"/>
<circle x="3.81" y="0" radius="1.04726875" width="0" layer="30"/>
</package>
<package name="AXIAL-0.1">
<wire x1="1.27" y1="-0.762" x2="1.27" y2="0" width="0.2032" layer="21"/>
<wire x1="1.27" y1="0" x2="1.27" y2="0.762" width="0.2032" layer="21"/>
<wire x1="1.524" y1="0" x2="1.27" y2="0" width="0.2032" layer="21"/>
<wire x1="1.27" y1="0" x2="1.016" y2="0" width="0.2032" layer="21"/>
<pad name="P$1" x="0" y="0" drill="0.9" diameter="1.8796"/>
<pad name="P$2" x="2.54" y="0" drill="0.9" diameter="1.8796"/>
<text x="0" y="1.27" size="1.016" layer="25" font="vector" ratio="15">&gt;Name</text>
<text x="0" y="-2.159" size="1.016" layer="21" font="vector" ratio="15">&gt;Value</text>
</package>
<package name="AXIAL-0.1EZ">
<wire x1="1.27" y1="-0.762" x2="1.27" y2="0" width="0.2032" layer="21"/>
<wire x1="1.27" y1="0" x2="1.27" y2="0.762" width="0.2032" layer="21"/>
<wire x1="1.524" y1="0" x2="1.27" y2="0" width="0.2032" layer="21"/>
<wire x1="1.27" y1="0" x2="1.016" y2="0" width="0.2032" layer="21"/>
<pad name="P$1" x="0" y="0" drill="0.9" diameter="1.8796" stop="no"/>
<pad name="P$2" x="2.54" y="0" drill="0.9" diameter="1.8796" stop="no"/>
<text x="0" y="1.27" size="1.016" layer="25" font="vector" ratio="15">&gt;Name</text>
<text x="0" y="-2.159" size="1.016" layer="21" font="vector" ratio="15">&gt;Value</text>
<circle x="0" y="0" radius="0.4572" width="0" layer="29"/>
<circle x="0" y="0" radius="1.016" width="0" layer="30"/>
<circle x="2.54" y="0" radius="1.016" width="0" layer="30"/>
<circle x="0" y="0" radius="0.4572" width="0" layer="29"/>
<circle x="2.54" y="0" radius="0.4572" width="0" layer="29"/>
</package>
</packages>
<symbols>
<symbol name="RESISTOR">
<wire x1="-2.54" y1="0" x2="-2.159" y2="1.016" width="0.1524" layer="94"/>
<wire x1="-2.159" y1="1.016" x2="-1.524" y2="-1.016" width="0.1524" layer="94"/>
<wire x1="-1.524" y1="-1.016" x2="-0.889" y2="1.016" width="0.1524" layer="94"/>
<wire x1="-0.889" y1="1.016" x2="-0.254" y2="-1.016" width="0.1524" layer="94"/>
<wire x1="-0.254" y1="-1.016" x2="0.381" y2="1.016" width="0.1524" layer="94"/>
<wire x1="0.381" y1="1.016" x2="1.016" y2="-1.016" width="0.1524" layer="94"/>
<wire x1="1.016" y1="-1.016" x2="1.651" y2="1.016" width="0.1524" layer="94"/>
<wire x1="1.651" y1="1.016" x2="2.286" y2="-1.016" width="0.1524" layer="94"/>
<wire x1="2.286" y1="-1.016" x2="2.54" y2="0" width="0.1524" layer="94"/>
<text x="-3.81" y="1.4986" size="1.778" layer="95">&gt;NAME</text>
<text x="-3.81" y="-3.302" size="1.778" layer="96">&gt;VALUE</text>
<pin name="2" x="5.08" y="0" visible="off" length="short" direction="pas" swaplevel="1" rot="R180"/>
<pin name="1" x="-5.08" y="0" visible="off" length="short" direction="pas" swaplevel="1"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="1KOHM-1/4W-1%(PTH)" prefix="R" uservalue="yes">
<description>RES-12182</description>
<gates>
<gate name="G$1" symbol="RESISTOR" x="0" y="0"/>
</gates>
<devices>
<device name="" package="AXIAL-0.3">
<connects>
<connect gate="G$1" pin="1" pad="P$1"/>
<connect gate="G$1" pin="2" pad="P$2"/>
</connects>
<technologies>
<technology name="">
<attribute name="PROD_ID" value="RES-12182" constant="no"/>
<attribute name="VALUE" value="1K" constant="no"/>
</technology>
</technologies>
</device>
<device name="HORIZ-KIT" package="AXIAL-0.3EZ">
<connects>
<connect gate="G$1" pin="1" pad="P$1"/>
<connect gate="G$1" pin="2" pad="P$2"/>
</connects>
<technologies>
<technology name="">
<attribute name="PROD_ID" value="RES-12182" constant="no"/>
<attribute name="VALUE" value="1K" constant="no"/>
</technology>
</technologies>
</device>
<device name="VERT" package="AXIAL-0.1">
<connects>
<connect gate="G$1" pin="1" pad="P$1"/>
<connect gate="G$1" pin="2" pad="P$2"/>
</connects>
<technologies>
<technology name="">
<attribute name="PROD_ID" value="RES-12182" constant="no"/>
<attribute name="VALUE" value="1K" constant="no"/>
</technology>
</technologies>
</device>
<device name="VERT-KIT" package="AXIAL-0.1EZ">
<connects>
<connect gate="G$1" pin="1" pad="P$1"/>
<connect gate="G$1" pin="2" pad="P$2"/>
</connects>
<technologies>
<technology name="">
<attribute name="PROD_ID" value="RES-12182" constant="no"/>
<attribute name="VALUE" value="1K" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="MakerWear">
<packages>
<package name="TQFP32-BREAKOUT">
<pad name="12" x="0" y="0" drill="0.8"/>
<pad name="11" x="0" y="2.54" drill="0.8"/>
<pad name="10" x="0" y="5.08" drill="0.8"/>
<pad name="9" x="0" y="7.62" drill="0.8"/>
<pad name="8" x="0" y="10.16" drill="0.8"/>
<pad name="7" x="0" y="12.7" drill="0.8"/>
<pad name="6" x="0" y="15.24" drill="0.8"/>
<pad name="5" x="0" y="17.78" drill="0.8"/>
<pad name="4" x="0" y="20.32" drill="0.8"/>
<pad name="3" x="0" y="22.86" drill="0.8"/>
<pad name="2" x="0" y="25.4" drill="0.8"/>
<pad name="1" x="0" y="27.94" drill="0.8"/>
<pad name="32" x="0" y="30.48" drill="0.8"/>
<pad name="31" x="0" y="33.02" drill="0.8"/>
<pad name="30" x="0" y="35.56" drill="0.8"/>
<pad name="29" x="0" y="38.1" drill="0.8"/>
<pad name="13" x="15.24" y="0" drill="0.8"/>
<pad name="14" x="15.24" y="2.54" drill="0.8"/>
<pad name="15" x="15.24" y="5.08" drill="0.8"/>
<pad name="16" x="15.24" y="7.62" drill="0.8"/>
<pad name="17" x="15.24" y="10.16" drill="0.8"/>
<pad name="18" x="15.24" y="12.7" drill="0.8"/>
<pad name="19" x="15.24" y="15.24" drill="0.8"/>
<pad name="20" x="15.24" y="17.78" drill="0.8"/>
<pad name="21" x="15.24" y="20.32" drill="0.8"/>
<pad name="22" x="15.24" y="22.86" drill="0.8"/>
<pad name="23" x="15.24" y="25.4" drill="0.8"/>
<pad name="24" x="15.24" y="27.94" drill="0.8"/>
<pad name="25" x="15.24" y="30.48" drill="0.8"/>
<pad name="26" x="15.24" y="33.02" drill="0.8"/>
<pad name="27" x="15.24" y="35.56" drill="0.8"/>
<pad name="28" x="15.24" y="38.1" drill="0.8"/>
<wire x1="-10.16" y1="41.91" x2="25.4" y2="41.91" width="0.8128" layer="21"/>
<wire x1="25.4" y1="41.91" x2="25.4" y2="-3.81" width="0.8128" layer="21"/>
<wire x1="25.4" y1="-3.81" x2="-10.16" y2="-3.81" width="0.8128" layer="21"/>
<wire x1="-10.16" y1="-3.81" x2="-10.16" y2="41.91" width="0.8128" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="ATMEGA328P-32PIN">
<wire x1="-25.4" y1="27.94" x2="27.94" y2="27.94" width="0.4064" layer="94"/>
<wire x1="27.94" y1="27.94" x2="27.94" y2="-27.94" width="0.4064" layer="94"/>
<wire x1="27.94" y1="-27.94" x2="-27.94" y2="-27.94" width="0.4064" layer="94"/>
<wire x1="-27.94" y1="-27.94" x2="-27.94" y2="25.4" width="0.4064" layer="94"/>
<wire x1="-27.94" y1="25.4" x2="-25.4" y2="27.94" width="0.4064" layer="94"/>
<pin name="P$1" x="-33.02" y="17.78" length="middle"/>
<pin name="P$2" x="-33.02" y="12.7" length="middle"/>
<pin name="P$3" x="-33.02" y="7.62" length="middle"/>
<pin name="P$4" x="-33.02" y="2.54" length="middle"/>
<pin name="P$5" x="-33.02" y="-2.54" length="middle"/>
<pin name="P$6" x="-33.02" y="-7.62" length="middle"/>
<pin name="P$7" x="-33.02" y="-12.7" length="middle"/>
<pin name="P$8" x="-33.02" y="-17.78" length="middle"/>
<pin name="P$9" x="-17.78" y="-33.02" length="middle" rot="R90"/>
<pin name="P$10" x="-12.7" y="-33.02" length="middle" rot="R90"/>
<pin name="P$11" x="-7.62" y="-33.02" length="middle" rot="R90"/>
<pin name="P$12" x="-2.54" y="-33.02" length="middle" rot="R90"/>
<pin name="P$13" x="2.54" y="-33.02" length="middle" rot="R90"/>
<pin name="P$14" x="7.62" y="-33.02" length="middle" rot="R90"/>
<pin name="P$15" x="12.7" y="-33.02" length="middle" rot="R90"/>
<pin name="P$16" x="17.78" y="-33.02" length="middle" rot="R90"/>
<pin name="P$17" x="33.02" y="-17.78" length="middle" rot="R180"/>
<pin name="P$18" x="33.02" y="-12.7" length="middle" rot="R180"/>
<pin name="P$19" x="33.02" y="-7.62" length="middle" rot="R180"/>
<pin name="P$20" x="33.02" y="-2.54" length="middle" rot="R180"/>
<pin name="P$21" x="33.02" y="2.54" length="middle" rot="R180"/>
<pin name="P$22" x="33.02" y="7.62" length="middle" rot="R180"/>
<pin name="P$23" x="33.02" y="12.7" length="middle" rot="R180"/>
<pin name="P$24" x="33.02" y="17.78" length="middle" rot="R180"/>
<pin name="P$25" x="17.78" y="33.02" length="middle" rot="R270"/>
<pin name="P$26" x="12.7" y="33.02" length="middle" rot="R270"/>
<pin name="P$27" x="7.62" y="33.02" length="middle" rot="R270"/>
<pin name="P$28" x="2.54" y="33.02" length="middle" rot="R270"/>
<pin name="P$29" x="-2.54" y="33.02" length="middle" rot="R270"/>
<pin name="P$30" x="-7.62" y="33.02" length="middle" rot="R270"/>
<pin name="P$31" x="-12.7" y="33.02" length="middle" rot="R270"/>
<pin name="P$32" x="-17.78" y="33.02" length="middle" rot="R270"/>
<circle x="-22.86" y="22.86" radius="1.27" width="0.4064" layer="94"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="ATMEGA-TQFP-BREAKOUT">
<gates>
<gate name="G$1" symbol="ATMEGA328P-32PIN" x="0" y="0"/>
</gates>
<devices>
<device name="" package="TQFP32-BREAKOUT">
<connects>
<connect gate="G$1" pin="P$1" pad="1"/>
<connect gate="G$1" pin="P$10" pad="10"/>
<connect gate="G$1" pin="P$11" pad="11"/>
<connect gate="G$1" pin="P$12" pad="12"/>
<connect gate="G$1" pin="P$13" pad="13"/>
<connect gate="G$1" pin="P$14" pad="14"/>
<connect gate="G$1" pin="P$15" pad="15"/>
<connect gate="G$1" pin="P$16" pad="16"/>
<connect gate="G$1" pin="P$17" pad="17"/>
<connect gate="G$1" pin="P$18" pad="18"/>
<connect gate="G$1" pin="P$19" pad="19"/>
<connect gate="G$1" pin="P$2" pad="2"/>
<connect gate="G$1" pin="P$20" pad="20"/>
<connect gate="G$1" pin="P$21" pad="21"/>
<connect gate="G$1" pin="P$22" pad="22"/>
<connect gate="G$1" pin="P$23" pad="23"/>
<connect gate="G$1" pin="P$24" pad="24"/>
<connect gate="G$1" pin="P$25" pad="25"/>
<connect gate="G$1" pin="P$26" pad="26"/>
<connect gate="G$1" pin="P$27" pad="27"/>
<connect gate="G$1" pin="P$28" pad="28"/>
<connect gate="G$1" pin="P$29" pad="29"/>
<connect gate="G$1" pin="P$3" pad="3"/>
<connect gate="G$1" pin="P$30" pad="30"/>
<connect gate="G$1" pin="P$31" pad="31"/>
<connect gate="G$1" pin="P$32" pad="32"/>
<connect gate="G$1" pin="P$4" pad="4"/>
<connect gate="G$1" pin="P$5" pad="5"/>
<connect gate="G$1" pin="P$6" pad="6"/>
<connect gate="G$1" pin="P$7" pad="7"/>
<connect gate="G$1" pin="P$8" pad="8"/>
<connect gate="G$1" pin="P$9" pad="9"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="SparkFun-Aesthetics">
<description>&lt;h3&gt;SparkFun Electronics' preferred foot prints&lt;/h3&gt;
In this library you'll find non-functional items- supply symbols, logos, notations, frame blocks, etc.&lt;br&gt;&lt;br&gt;
We've spent an enormous amount of time creating and checking these footprints and parts, but it is the end user's responsibility to ensure correctness and suitablity for a given componet or application. If you enjoy using this library, please buy one of our products at www.sparkfun.com.
&lt;br&gt;&lt;br&gt;
&lt;b&gt;Licensing:&lt;/b&gt; Creative Commons ShareAlike 4.0 International - https://creativecommons.org/licenses/by-sa/4.0/ 
&lt;br&gt;&lt;br&gt;
You are welcome to use this library for commercial purposes. For attribution, we ask that when you begin to sell your device using our footprint, you email us with a link to the product being sold. We want bragging rights that we helped (in a very small part) to create your 8th world wonder. We would like the opportunity to feature your device on our homepage.</description>
<packages>
</packages>
<symbols>
<symbol name="DGND">
<wire x1="-1.905" y1="0" x2="1.905" y2="0" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96">&gt;VALUE</text>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
<symbol name="VCC">
<wire x1="0.762" y1="1.27" x2="0" y2="2.54" width="0.254" layer="94"/>
<wire x1="0" y1="2.54" x2="-0.762" y2="1.27" width="0.254" layer="94"/>
<text x="-1.016" y="3.556" size="1.778" layer="96">&gt;VALUE</text>
<pin name="VCC" x="0" y="0" visible="off" length="short" direction="sup" rot="R90"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="GND" prefix="GND">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="DGND" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="VCC" prefix="SUPPLY">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="VCC" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="J1" library="SparkFun-Boards" deviceset="ARDUINO_R3_SHIELD" device=""/>
<part name="R1" library="SparkFun-Resistors" deviceset="1KOHM-1/4W-1%(PTH)" device="" value="1K"/>
<part name="U$1" library="MakerWear" deviceset="ATMEGA-TQFP-BREAKOUT" device=""/>
<part name="GND1" library="SparkFun-Aesthetics" deviceset="GND" device=""/>
<part name="GND2" library="SparkFun-Aesthetics" deviceset="GND" device=""/>
<part name="GND3" library="SparkFun-Aesthetics" deviceset="GND" device=""/>
<part name="GND4" library="SparkFun-Aesthetics" deviceset="GND" device=""/>
<part name="SUPPLY1" library="SparkFun-Aesthetics" deviceset="VCC" device=""/>
<part name="SUPPLY2" library="SparkFun-Aesthetics" deviceset="VCC" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="J1" gate="G$1" x="0" y="0"/>
<instance part="R1" gate="G$1" x="119.38" y="53.34" rot="MR270"/>
<instance part="U$1" gate="G$1" x="121.92" y="-2.54"/>
<instance part="GND1" gate="1" x="167.64" y="-7.62" rot="MR0"/>
<instance part="GND2" gate="1" x="-20.32" y="-30.48" rot="MR0"/>
<instance part="GND3" gate="1" x="-27.94" y="-30.48" rot="MR0"/>
<instance part="GND4" gate="1" x="-35.56" y="-30.48" rot="MR0"/>
<instance part="SUPPLY1" gate="G$1" x="119.38" y="63.5"/>
<instance part="SUPPLY2" gate="G$1" x="-35.56" y="2.54"/>
</instances>
<busses>
</busses>
<nets>
<net name="GND" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="P$21"/>
<pinref part="GND1" gate="1" pin="GND"/>
<wire x1="154.94" y1="0" x2="167.64" y2="0" width="0.1524" layer="91"/>
<wire x1="167.64" y1="0" x2="167.64" y2="-5.08" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="J1" gate="G$1" pin="GND@0"/>
<pinref part="GND2" gate="1" pin="GND"/>
<wire x1="-12.7" y1="-22.86" x2="-20.32" y2="-22.86" width="0.1524" layer="91"/>
<wire x1="-20.32" y1="-22.86" x2="-20.32" y2="-27.94" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="J1" gate="G$1" pin="GND@1"/>
<pinref part="GND3" gate="1" pin="GND"/>
<wire x1="-12.7" y1="-20.32" x2="-27.94" y2="-20.32" width="0.1524" layer="91"/>
<wire x1="-27.94" y1="-20.32" x2="-27.94" y2="-27.94" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="J1" gate="G$1" pin="GND@2"/>
<pinref part="GND4" gate="1" pin="GND"/>
<wire x1="-12.7" y1="-17.78" x2="-35.56" y2="-17.78" width="0.1524" layer="91"/>
<wire x1="-35.56" y1="-17.78" x2="-35.56" y2="-27.94" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="P$3"/>
<wire x1="88.9" y1="5.08" x2="76.2" y2="5.08" width="0.1524" layer="91"/>
<junction x="76.2" y="5.08"/>
<label x="78.74" y="5.08" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="P$5"/>
<wire x1="88.9" y1="-5.08" x2="76.2" y2="-5.08" width="0.1524" layer="91"/>
<junction x="76.2" y="-5.08"/>
<label x="78.74" y="-5.08" size="1.778" layer="95"/>
</segment>
</net>
<net name="SCK" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="P$17"/>
<wire x1="154.94" y1="-20.32" x2="167.64" y2="-20.32" width="0.1524" layer="91"/>
<label x="160.02" y="-20.32" size="1.778" layer="95"/>
<junction x="167.64" y="-20.32"/>
</segment>
<segment>
<pinref part="J1" gate="G$1" pin="D13"/>
<wire x1="12.7" y1="-17.78" x2="25.4" y2="-17.78" width="0.1524" layer="91"/>
<label x="15.24" y="-17.78" size="1.778" layer="95"/>
<junction x="25.4" y="-17.78"/>
</segment>
</net>
<net name="MISO" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="P$16"/>
<wire x1="139.7" y1="-35.56" x2="139.7" y2="-43.18" width="0.1524" layer="91"/>
<wire x1="139.7" y1="-43.18" x2="167.64" y2="-43.18" width="0.1524" layer="91"/>
<label x="160.02" y="-43.18" size="1.778" layer="95"/>
<junction x="167.64" y="-43.18"/>
</segment>
<segment>
<pinref part="J1" gate="G$1" pin="D12"/>
<wire x1="12.7" y1="-15.24" x2="25.4" y2="-15.24" width="0.1524" layer="91"/>
<label x="15.24" y="-15.24" size="1.778" layer="95"/>
<junction x="25.4" y="-15.24"/>
</segment>
</net>
<net name="MOSI" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="P$15"/>
<wire x1="134.62" y1="-35.56" x2="134.62" y2="-48.26" width="0.1524" layer="91"/>
<wire x1="134.62" y1="-48.26" x2="167.64" y2="-48.26" width="0.1524" layer="91"/>
<label x="160.02" y="-48.26" size="1.778" layer="95"/>
<junction x="167.64" y="-48.26"/>
</segment>
<segment>
<pinref part="J1" gate="G$1" pin="*D11"/>
<wire x1="12.7" y1="-12.7" x2="25.4" y2="-12.7" width="0.1524" layer="91"/>
<label x="15.24" y="-12.7" size="1.778" layer="95"/>
<junction x="25.4" y="-12.7"/>
</segment>
</net>
<net name="RESET" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="P$29"/>
<wire x1="119.38" y1="30.48" x2="119.38" y2="40.64" width="0.1524" layer="91"/>
<pinref part="R1" gate="G$1" pin="2"/>
<wire x1="119.38" y1="40.64" x2="119.38" y2="48.26" width="0.1524" layer="91"/>
<wire x1="119.38" y1="40.64" x2="91.44" y2="40.64" width="0.1524" layer="91"/>
<junction x="119.38" y="40.64"/>
<label x="101.6" y="40.64" size="1.778" layer="95"/>
<junction x="91.44" y="40.64"/>
</segment>
<segment>
<pinref part="J1" gate="G$1" pin="*D10"/>
<wire x1="12.7" y1="-10.16" x2="25.4" y2="-10.16" width="0.1524" layer="91"/>
<label x="15.24" y="-10.16" size="1.778" layer="95"/>
<junction x="25.4" y="-10.16"/>
</segment>
</net>
<net name="VCC" class="0">
<segment>
<pinref part="SUPPLY1" gate="G$1" pin="VCC"/>
<pinref part="R1" gate="G$1" pin="1"/>
<wire x1="119.38" y1="63.5" x2="119.38" y2="58.42" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="J1" gate="G$1" pin="5V"/>
<pinref part="SUPPLY2" gate="G$1" pin="VCC"/>
<wire x1="-12.7" y1="-10.16" x2="-35.56" y2="-10.16" width="0.1524" layer="91"/>
<wire x1="-35.56" y1="-10.16" x2="-35.56" y2="2.54" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="P$4"/>
<wire x1="88.9" y1="0" x2="76.2" y2="0" width="0.1524" layer="91"/>
<label x="78.74" y="0" size="1.778" layer="95"/>
<junction x="76.2" y="0"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="P$6"/>
<wire x1="88.9" y1="-10.16" x2="76.2" y2="-10.16" width="0.1524" layer="91"/>
<label x="78.74" y="-10.16" size="1.778" layer="95"/>
<junction x="76.2" y="-10.16"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
