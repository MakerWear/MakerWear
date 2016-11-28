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
<layer number="114" name="Badge_Outline" color="7" fill="1" visible="yes" active="yes"/>
<layer number="115" name="ReferenceISLANDS" color="7" fill="1" visible="yes" active="yes"/>
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
<library name="MakerShoe">
<packages>
<package name="SHIELD_FINGER_PKG">
<smd name="P2" x="0.0254" y="-0.8128" dx="1.5" dy="0.6" layer="16"/>
<smd name="P1" x="0.0254" y="0.7872" dx="1.5" dy="0.6" layer="16"/>
<wire x1="0.9254" y1="-1.2128" x2="-2.5746" y2="-1.2128" width="0.127" layer="52"/>
<wire x1="-2.5746" y1="-1.2128" x2="-2.5746" y2="1.1872" width="0.127" layer="52"/>
<wire x1="-2.5746" y1="1.1872" x2="0.9254" y2="1.1872" width="0.127" layer="52"/>
<wire x1="0.9254" y1="1.1872" x2="0.9254" y2="0.2872" width="0.127" layer="52"/>
<wire x1="0.9254" y1="0.2872" x2="-1.3746" y2="0.2872" width="0.127" layer="52"/>
<wire x1="-1.3746" y1="0.2872" x2="-1.3746" y2="-0.3128" width="0.127" layer="52"/>
<wire x1="-1.3746" y1="-0.3128" x2="0.9254" y2="-0.3128" width="0.127" layer="52"/>
<wire x1="0.9254" y1="-0.3128" x2="0.9254" y2="-1.2128" width="0.127" layer="52"/>
<rectangle x1="-0.2246" y1="-0.7128" x2="0.2254" y2="0.6872" layer="16"/>
</package>
</packages>
<symbols>
<symbol name="SHIELD_FINGER_0820">
<description>http://www.digikey.com/product-detail/en/2040852-1/A118093CT-ND/4730012</description>
<wire x1="0" y1="0" x2="0" y2="5.08" width="0.254" layer="94"/>
<wire x1="0" y1="5.08" x2="7.62" y2="5.08" width="0.254" layer="94"/>
<wire x1="7.62" y1="5.08" x2="7.62" y2="0" width="0.254" layer="94"/>
<wire x1="7.62" y1="0" x2="0" y2="0" width="0.254" layer="94"/>
<pin name="PIN" x="12.7" y="2.54" length="middle" rot="R180"/>
<text x="-0.254" y="5.842" size="1.778" layer="95">&gt;NAME</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="SHIELD_FINGER">
<gates>
<gate name="G$1" symbol="SHIELD_FINGER_0820" x="0" y="0"/>
</gates>
<devices>
<device name="0820" package="SHIELD_FINGER_PKG">
<connects>
<connect gate="G$1" pin="PIN" pad="P1 P2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="MakerWear">
<packages>
<package name="2X4">
<wire x1="-5.08" y1="-1.905" x2="-4.445" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="-2.54" x2="-2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="-1.905" x2="-1.905" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-2.54" x2="0" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="0" y1="-1.905" x2="0.635" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-2.54" x2="2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-1.905" x2="3.175" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="4.445" y1="-2.54" x2="5.08" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-1.905" x2="-5.08" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="1.905" x2="-4.445" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="2.54" x2="-3.175" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="2.54" x2="-2.54" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="1.905" x2="-1.905" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="2.54" x2="-0.635" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="2.54" x2="0" y2="1.905" width="0.1524" layer="21"/>
<wire x1="0" y1="1.905" x2="0.635" y2="2.54" width="0.1524" layer="21"/>
<wire x1="0.635" y1="2.54" x2="1.905" y2="2.54" width="0.1524" layer="21"/>
<wire x1="1.905" y1="2.54" x2="2.54" y2="1.905" width="0.1524" layer="21"/>
<wire x1="2.54" y1="1.905" x2="3.175" y2="2.54" width="0.1524" layer="21"/>
<wire x1="3.175" y1="2.54" x2="4.445" y2="2.54" width="0.1524" layer="21"/>
<wire x1="4.445" y1="2.54" x2="5.08" y2="1.905" width="0.1524" layer="21"/>
<wire x1="5.08" y1="1.905" x2="5.08" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="3.175" y1="-2.54" x2="4.445" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-2.54" x2="1.905" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-2.54" x2="-0.635" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="-2.54" x2="-3.175" y2="-2.54" width="0.1524" layer="21"/>
<text x="-5.08" y="3.175" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-5.08" y="-4.445" size="1.27" layer="27">&gt;VALUE</text>
<smd name="P$1" x="-3.81" y="-1.27" dx="1.524" dy="1.524" layer="1" roundness="100"/>
<smd name="P$2" x="-1.27" y="-1.27" dx="1.524" dy="1.524" layer="1" roundness="100"/>
<smd name="P$3" x="1.27" y="-1.27" dx="1.524" dy="1.524" layer="1" roundness="100"/>
<smd name="P$4" x="3.81" y="-1.27" dx="1.524" dy="1.524" layer="1" roundness="100"/>
<smd name="P$5" x="3.81" y="1.27" dx="1.524" dy="1.524" layer="1" roundness="100"/>
<smd name="P$6" x="1.27" y="1.27" dx="1.524" dy="1.524" layer="1" roundness="100"/>
<smd name="P$7" x="-1.27" y="1.27" dx="1.524" dy="1.524" layer="1" roundness="100"/>
<smd name="P$8" x="-3.81" y="1.27" dx="1.524" dy="1.524" layer="1" roundness="100"/>
</package>
</packages>
<symbols>
<symbol name="M04X2">
<wire x1="-1.27" y1="0" x2="-2.54" y2="0" width="0.6096" layer="94"/>
<wire x1="-1.27" y1="2.54" x2="-2.54" y2="2.54" width="0.6096" layer="94"/>
<wire x1="-1.27" y1="5.08" x2="-2.54" y2="5.08" width="0.6096" layer="94"/>
<wire x1="-3.81" y1="7.62" x2="-3.81" y2="-5.08" width="0.4064" layer="94"/>
<wire x1="-1.27" y1="-2.54" x2="-2.54" y2="-2.54" width="0.6096" layer="94"/>
<wire x1="3.81" y1="-5.08" x2="-3.81" y2="-5.08" width="0.4064" layer="94"/>
<wire x1="3.81" y1="-5.08" x2="3.81" y2="7.62" width="0.4064" layer="94"/>
<wire x1="-3.81" y1="7.62" x2="3.81" y2="7.62" width="0.4064" layer="94"/>
<wire x1="1.27" y1="-2.54" x2="2.54" y2="-2.54" width="0.6096" layer="94"/>
<wire x1="1.27" y1="0" x2="2.54" y2="0" width="0.6096" layer="94"/>
<wire x1="1.27" y1="2.54" x2="2.54" y2="2.54" width="0.6096" layer="94"/>
<wire x1="1.27" y1="5.08" x2="2.54" y2="5.08" width="0.6096" layer="94"/>
<text x="-4.572" y="-7.62" size="1.778" layer="96">&gt;VALUE</text>
<text x="-4.064" y="8.382" size="1.778" layer="95">&gt;NAME</text>
<pin name="1" x="-7.62" y="5.08" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="2" x="7.62" y="5.08" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="3" x="-7.62" y="2.54" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="4" x="7.62" y="2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="5" x="-7.62" y="0" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="6" x="7.62" y="0" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="7" x="-7.62" y="-2.54" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="8" x="7.62" y="-2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="M04X2" prefix="JP" uservalue="yes">
<description>.1" header, two rows of four.</description>
<gates>
<gate name="G$1" symbol="M04X2" x="0" y="0"/>
</gates>
<devices>
<device name="" package="2X4">
<connects>
<connect gate="G$1" pin="1" pad="P$1"/>
<connect gate="G$1" pin="2" pad="P$2"/>
<connect gate="G$1" pin="3" pad="P$3"/>
<connect gate="G$1" pin="4" pad="P$4"/>
<connect gate="G$1" pin="5" pad="P$5"/>
<connect gate="G$1" pin="6" pad="P$6"/>
<connect gate="G$1" pin="7" pad="P$7"/>
<connect gate="G$1" pin="8" pad="P$8"/>
</connects>
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
<part name="CON3" library="MakerShoe" deviceset="SHIELD_FINGER" device="0820"/>
<part name="CON2" library="MakerShoe" deviceset="SHIELD_FINGER" device="0820"/>
<part name="CON4" library="MakerShoe" deviceset="SHIELD_FINGER" device="0820"/>
<part name="CON5" library="MakerShoe" deviceset="SHIELD_FINGER" device="0820"/>
<part name="CON6" library="MakerShoe" deviceset="SHIELD_FINGER" device="0820"/>
<part name="CON7" library="MakerShoe" deviceset="SHIELD_FINGER" device="0820"/>
<part name="CON8" library="MakerShoe" deviceset="SHIELD_FINGER" device="0820"/>
<part name="CON9" library="MakerShoe" deviceset="SHIELD_FINGER" device="0820"/>
<part name="CON1" library="MakerShoe" deviceset="SHIELD_FINGER" device="0820"/>
<part name="JP1" library="MakerWear" deviceset="M04X2" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="CON3" gate="G$1" x="0" y="15.24"/>
<instance part="CON2" gate="G$1" x="0" y="25.4"/>
<instance part="CON4" gate="G$1" x="-40.64" y="35.56"/>
<instance part="CON5" gate="G$1" x="-40.64" y="25.4"/>
<instance part="CON6" gate="G$1" x="-40.64" y="15.24"/>
<instance part="CON7" gate="G$1" x="-83.82" y="35.56"/>
<instance part="CON8" gate="G$1" x="-83.82" y="25.4"/>
<instance part="CON9" gate="G$1" x="-83.82" y="15.24"/>
<instance part="CON1" gate="G$1" x="0" y="35.56"/>
<instance part="JP1" gate="G$1" x="68.58" y="27.94"/>
</instances>
<busses>
</busses>
<nets>
<net name="SIN1" class="0">
<segment>
<pinref part="CON7" gate="G$1" pin="PIN"/>
<wire x1="-71.12" y1="38.1" x2="-58.42" y2="38.1" width="0.1524" layer="91"/>
<label x="-66.04" y="38.1" size="1.778" layer="95"/>
<label x="-58.42" y="38.1" size="1.27" layer="95" xref="yes"/>
</segment>
<segment>
<wire x1="76.2" y1="27.94" x2="81.28" y2="27.94" width="0.1524" layer="91"/>
<label x="81.28" y="27.94" size="0.762" layer="95" ratio="5" xref="yes"/>
<pinref part="JP1" gate="G$1" pin="6"/>
</segment>
</net>
<net name="SIN2" class="0">
<segment>
<pinref part="CON8" gate="G$1" pin="PIN"/>
<wire x1="-71.12" y1="27.94" x2="-58.42" y2="27.94" width="0.1524" layer="91"/>
<label x="-66.04" y="27.94" size="1.778" layer="95"/>
<label x="-58.42" y="27.94" size="1.27" layer="95" xref="yes"/>
</segment>
<segment>
<wire x1="76.2" y1="30.48" x2="81.28" y2="30.48" width="0.1524" layer="91"/>
<label x="81.28" y="30.48" size="0.762" layer="95" ratio="5" xref="yes"/>
<pinref part="JP1" gate="G$1" pin="4"/>
</segment>
</net>
<net name="SIN3" class="0">
<segment>
<pinref part="CON9" gate="G$1" pin="PIN"/>
<wire x1="-71.12" y1="17.78" x2="-58.42" y2="17.78" width="0.1524" layer="91"/>
<label x="-66.04" y="17.78" size="1.778" layer="95"/>
<label x="-58.42" y="17.78" size="1.27" layer="95" xref="yes"/>
</segment>
<segment>
<wire x1="76.2" y1="33.02" x2="81.28" y2="33.02" width="0.1524" layer="91"/>
<label x="81.28" y="33.02" size="0.762" layer="95" ratio="5" xref="yes"/>
<pinref part="JP1" gate="G$1" pin="2"/>
</segment>
</net>
<net name="SOUT1" class="0">
<segment>
<pinref part="CON4" gate="G$1" pin="PIN"/>
<wire x1="-27.94" y1="38.1" x2="-15.24" y2="38.1" width="0.1524" layer="91"/>
<label x="-25.4" y="38.1" size="1.778" layer="95"/>
<label x="-15.24" y="38.1" size="1.27" layer="95" xref="yes"/>
</segment>
<segment>
<wire x1="60.96" y1="30.48" x2="55.88" y2="30.48" width="0.1524" layer="91"/>
<label x="55.88" y="30.48" size="0.762" layer="95" ratio="5" rot="R180" xref="yes"/>
<pinref part="JP1" gate="G$1" pin="3"/>
</segment>
</net>
<net name="SOUT2" class="0">
<segment>
<pinref part="CON5" gate="G$1" pin="PIN"/>
<wire x1="-27.94" y1="27.94" x2="-15.24" y2="27.94" width="0.1524" layer="91"/>
<label x="-25.4" y="27.94" size="1.778" layer="95"/>
<label x="-15.24" y="27.94" size="1.27" layer="95" xref="yes"/>
</segment>
<segment>
<wire x1="60.96" y1="27.94" x2="55.88" y2="27.94" width="0.1524" layer="91"/>
<label x="55.88" y="27.94" size="0.762" layer="95" ratio="5" rot="R180" xref="yes"/>
<pinref part="JP1" gate="G$1" pin="5"/>
</segment>
</net>
<net name="SOUT3" class="0">
<segment>
<pinref part="CON6" gate="G$1" pin="PIN"/>
<wire x1="-27.94" y1="17.78" x2="-15.24" y2="17.78" width="0.1524" layer="91"/>
<label x="-25.4" y="17.78" size="1.778" layer="95"/>
<label x="-15.24" y="17.78" size="1.27" layer="95" xref="yes"/>
</segment>
<segment>
<wire x1="60.96" y1="25.4" x2="55.88" y2="25.4" width="0.1524" layer="91"/>
<label x="55.88" y="25.4" size="0.762" layer="95" ratio="5" rot="R180" xref="yes"/>
<pinref part="JP1" gate="G$1" pin="7"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="CON3" gate="G$1" pin="PIN"/>
<wire x1="12.7" y1="17.78" x2="27.94" y2="17.78" width="0.1524" layer="91"/>
<label x="17.78" y="17.78" size="1.778" layer="95"/>
<label x="27.94" y="17.78" size="1.27" layer="95" xref="yes"/>
</segment>
<segment>
<wire x1="76.2" y1="25.4" x2="81.28" y2="25.4" width="0.1524" layer="91"/>
<label x="81.28" y="25.4" size="0.762" layer="95" ratio="5" xref="yes"/>
<pinref part="JP1" gate="G$1" pin="8"/>
</segment>
</net>
<net name="VCC" class="0">
<segment>
<wire x1="60.96" y1="33.02" x2="55.88" y2="33.02" width="0.1524" layer="91"/>
<label x="55.88" y="33.02" size="0.762" layer="95" ratio="5" rot="R180" xref="yes"/>
<pinref part="JP1" gate="G$1" pin="1"/>
</segment>
<segment>
<pinref part="CON2" gate="G$1" pin="PIN"/>
<wire x1="12.7" y1="27.94" x2="27.94" y2="27.94" width="0.1524" layer="91"/>
<label x="17.78" y="27.94" size="1.778" layer="95"/>
<label x="27.94" y="27.94" size="1.27" layer="95" xref="yes"/>
</segment>
<segment>
<pinref part="CON1" gate="G$1" pin="PIN"/>
<wire x1="12.7" y1="38.1" x2="27.94" y2="38.1" width="0.1524" layer="91"/>
<label x="17.78" y="38.1" size="1.778" layer="95"/>
<label x="27.94" y="38.1" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
<errors>
<approved hash="113,1,6.94267,4.00473,JP1,,,,,"/>
<approved hash="113,1,6.94267,19.2447,JP2,,,,,"/>
<approved hash="113,1,6.94267,34.4847,JP3,,,,,"/>
<approved hash="113,1,79.9248,31.7415,PWR-SW,,,,,"/>
<approved hash="113,1,89.2217,21.59,D1,,,,,"/>
</errors>
</schematic>
</drawing>
</eagle>
