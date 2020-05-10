// Generated by gencpp from file carla_msgs/CarlaEgoVehicleInfo.msg
// DO NOT EDIT!


#ifndef CARLA_MSGS_MESSAGE_CARLAEGOVEHICLEINFO_H
#define CARLA_MSGS_MESSAGE_CARLAEGOVEHICLEINFO_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <carla_msgs/CarlaEgoVehicleInfoWheel.h>
#include <geometry_msgs/Vector3.h>

namespace carla_msgs
{
template <class ContainerAllocator>
struct CarlaEgoVehicleInfo_
{
  typedef CarlaEgoVehicleInfo_<ContainerAllocator> Type;

  CarlaEgoVehicleInfo_()
    : id(0)
    , type()
    , rolename()
    , wheels()
    , max_rpm(0.0)
    , moi(0.0)
    , damping_rate_full_throttle(0.0)
    , damping_rate_zero_throttle_clutch_engaged(0.0)
    , damping_rate_zero_throttle_clutch_disengaged(0.0)
    , use_gear_autobox(false)
    , gear_switch_time(0.0)
    , clutch_strength(0.0)
    , mass(0.0)
    , drag_coefficient(0.0)
    , center_of_mass()  {
    }
  CarlaEgoVehicleInfo_(const ContainerAllocator& _alloc)
    : id(0)
    , type(_alloc)
    , rolename(_alloc)
    , wheels(_alloc)
    , max_rpm(0.0)
    , moi(0.0)
    , damping_rate_full_throttle(0.0)
    , damping_rate_zero_throttle_clutch_engaged(0.0)
    , damping_rate_zero_throttle_clutch_disengaged(0.0)
    , use_gear_autobox(false)
    , gear_switch_time(0.0)
    , clutch_strength(0.0)
    , mass(0.0)
    , drag_coefficient(0.0)
    , center_of_mass(_alloc)  {
  (void)_alloc;
    }



   typedef uint32_t _id_type;
  _id_type id;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _type_type;
  _type_type type;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _rolename_type;
  _rolename_type rolename;

   typedef std::vector< ::carla_msgs::CarlaEgoVehicleInfoWheel_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::carla_msgs::CarlaEgoVehicleInfoWheel_<ContainerAllocator> >::other >  _wheels_type;
  _wheels_type wheels;

   typedef float _max_rpm_type;
  _max_rpm_type max_rpm;

   typedef float _moi_type;
  _moi_type moi;

   typedef float _damping_rate_full_throttle_type;
  _damping_rate_full_throttle_type damping_rate_full_throttle;

   typedef float _damping_rate_zero_throttle_clutch_engaged_type;
  _damping_rate_zero_throttle_clutch_engaged_type damping_rate_zero_throttle_clutch_engaged;

   typedef float _damping_rate_zero_throttle_clutch_disengaged_type;
  _damping_rate_zero_throttle_clutch_disengaged_type damping_rate_zero_throttle_clutch_disengaged;

   typedef uint8_t _use_gear_autobox_type;
  _use_gear_autobox_type use_gear_autobox;

   typedef float _gear_switch_time_type;
  _gear_switch_time_type gear_switch_time;

   typedef float _clutch_strength_type;
  _clutch_strength_type clutch_strength;

   typedef float _mass_type;
  _mass_type mass;

   typedef float _drag_coefficient_type;
  _drag_coefficient_type drag_coefficient;

   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _center_of_mass_type;
  _center_of_mass_type center_of_mass;





  typedef boost::shared_ptr< ::carla_msgs::CarlaEgoVehicleInfo_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::carla_msgs::CarlaEgoVehicleInfo_<ContainerAllocator> const> ConstPtr;

}; // struct CarlaEgoVehicleInfo_

typedef ::carla_msgs::CarlaEgoVehicleInfo_<std::allocator<void> > CarlaEgoVehicleInfo;

typedef boost::shared_ptr< ::carla_msgs::CarlaEgoVehicleInfo > CarlaEgoVehicleInfoPtr;
typedef boost::shared_ptr< ::carla_msgs::CarlaEgoVehicleInfo const> CarlaEgoVehicleInfoConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::carla_msgs::CarlaEgoVehicleInfo_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::carla_msgs::CarlaEgoVehicleInfo_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace carla_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'geometry_msgs': ['/opt/ros/melodic/share/geometry_msgs/cmake/../msg'], 'carla_msgs': ['/home/janmart/carla-ros-bridge/catkin_ws/src/ros-bridge/carla_msgs/msg'], 'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::carla_msgs::CarlaEgoVehicleInfo_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::carla_msgs::CarlaEgoVehicleInfo_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::carla_msgs::CarlaEgoVehicleInfo_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::carla_msgs::CarlaEgoVehicleInfo_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::carla_msgs::CarlaEgoVehicleInfo_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::carla_msgs::CarlaEgoVehicleInfo_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::carla_msgs::CarlaEgoVehicleInfo_<ContainerAllocator> >
{
  static const char* value()
  {
    return "380b84c67059884787e0b582a7236281";
  }

  static const char* value(const ::carla_msgs::CarlaEgoVehicleInfo_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x380b84c670598847ULL;
  static const uint64_t static_value2 = 0x87e0b582a7236281ULL;
};

template<class ContainerAllocator>
struct DataType< ::carla_msgs::CarlaEgoVehicleInfo_<ContainerAllocator> >
{
  static const char* value()
  {
    return "carla_msgs/CarlaEgoVehicleInfo";
  }

  static const char* value(const ::carla_msgs::CarlaEgoVehicleInfo_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::carla_msgs::CarlaEgoVehicleInfo_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#\n"
"# Copyright (c) 2019 Intel Corporation.\n"
"#\n"
"# This work is licensed under the terms of the MIT license.\n"
"# For a copy, see <https://opensource.org/licenses/MIT>.\n"
"#\n"
"\n"
"uint32 id\n"
"string type\n"
"string rolename\n"
"CarlaEgoVehicleInfoWheel[] wheels\n"
"float32 max_rpm\n"
"float32 moi\n"
"float32 damping_rate_full_throttle\n"
"float32 damping_rate_zero_throttle_clutch_engaged\n"
"float32 damping_rate_zero_throttle_clutch_disengaged\n"
"bool use_gear_autobox\n"
"float32 gear_switch_time\n"
"float32 clutch_strength\n"
"float32 mass\n"
"float32 drag_coefficient\n"
"geometry_msgs/Vector3 center_of_mass\n"
"\n"
"================================================================================\n"
"MSG: carla_msgs/CarlaEgoVehicleInfoWheel\n"
"#\n"
"# Copyright (c) 2019 Intel Corporation.\n"
"#\n"
"# This work is licensed under the terms of the MIT license.\n"
"# For a copy, see <https://opensource.org/licenses/MIT>.\n"
"#\n"
"float32 tire_friction\n"
"float32 damping_rate\n"
"float32 max_steer_angle\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Vector3\n"
"# This represents a vector in free space. \n"
"# It is only meant to represent a direction. Therefore, it does not\n"
"# make sense to apply a translation to it (e.g., when applying a \n"
"# generic rigid transformation to a Vector3, tf2 will only apply the\n"
"# rotation). If you want your data to be translatable too, use the\n"
"# geometry_msgs/Point message instead.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
;
  }

  static const char* value(const ::carla_msgs::CarlaEgoVehicleInfo_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::carla_msgs::CarlaEgoVehicleInfo_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.id);
      stream.next(m.type);
      stream.next(m.rolename);
      stream.next(m.wheels);
      stream.next(m.max_rpm);
      stream.next(m.moi);
      stream.next(m.damping_rate_full_throttle);
      stream.next(m.damping_rate_zero_throttle_clutch_engaged);
      stream.next(m.damping_rate_zero_throttle_clutch_disengaged);
      stream.next(m.use_gear_autobox);
      stream.next(m.gear_switch_time);
      stream.next(m.clutch_strength);
      stream.next(m.mass);
      stream.next(m.drag_coefficient);
      stream.next(m.center_of_mass);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct CarlaEgoVehicleInfo_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::carla_msgs::CarlaEgoVehicleInfo_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::carla_msgs::CarlaEgoVehicleInfo_<ContainerAllocator>& v)
  {
    s << indent << "id: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.id);
    s << indent << "type: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.type);
    s << indent << "rolename: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.rolename);
    s << indent << "wheels[]" << std::endl;
    for (size_t i = 0; i < v.wheels.size(); ++i)
    {
      s << indent << "  wheels[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::carla_msgs::CarlaEgoVehicleInfoWheel_<ContainerAllocator> >::stream(s, indent + "    ", v.wheels[i]);
    }
    s << indent << "max_rpm: ";
    Printer<float>::stream(s, indent + "  ", v.max_rpm);
    s << indent << "moi: ";
    Printer<float>::stream(s, indent + "  ", v.moi);
    s << indent << "damping_rate_full_throttle: ";
    Printer<float>::stream(s, indent + "  ", v.damping_rate_full_throttle);
    s << indent << "damping_rate_zero_throttle_clutch_engaged: ";
    Printer<float>::stream(s, indent + "  ", v.damping_rate_zero_throttle_clutch_engaged);
    s << indent << "damping_rate_zero_throttle_clutch_disengaged: ";
    Printer<float>::stream(s, indent + "  ", v.damping_rate_zero_throttle_clutch_disengaged);
    s << indent << "use_gear_autobox: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.use_gear_autobox);
    s << indent << "gear_switch_time: ";
    Printer<float>::stream(s, indent + "  ", v.gear_switch_time);
    s << indent << "clutch_strength: ";
    Printer<float>::stream(s, indent + "  ", v.clutch_strength);
    s << indent << "mass: ";
    Printer<float>::stream(s, indent + "  ", v.mass);
    s << indent << "drag_coefficient: ";
    Printer<float>::stream(s, indent + "  ", v.drag_coefficient);
    s << indent << "center_of_mass: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.center_of_mass);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CARLA_MSGS_MESSAGE_CARLAEGOVEHICLEINFO_H
