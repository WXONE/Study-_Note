public class Exp_3 extends  RuntimeException{
      private static final long serialVersionUID = 1L;


//错误编码
      private String errorCode;

//消息是否为文件中的key
      private boolean propertiesKey = true;

//构造一个基本异常，信息描述
      public Exp_3(String message) {

          super(message);
      }

//构造一个基本异常，错误编码，信息描述
      public Exp_3(String errorCode, String message){

         this(errorCode, message, true);
     }

//构造一个基本异常，错误编码，信息描述，原因

      public Exp_3(String errorCode, String message, Throwable cause){

         this(errorCode, message, cause, true);
     }

//构造一个基本异常，错误编码，信息描述

      public Exp_3(String errorCode, String message, boolean propertiesKey){

         super(message);
         this.setErrorCode(errorCode);
         this.setPropertiesKey(propertiesKey);
     }


      public Exp_3(String errorCode, String message, Throwable cause, boolean propertiesKey){

         super(message, cause);
         this.setErrorCode(errorCode);
         this.setPropertiesKey(propertiesKey);
     }


      public Exp_3(String message, Throwable cause){

          super(message, cause);
      }

      public String getErrorCode(){

        return errorCode;
      }

      public void setErrorCode(String errorCode){

          this.errorCode = errorCode;
      }

      public boolean isPropertiesKey(){

          return propertiesKey;
      }

      public void setPropertiesKey(boolean propertiesKey){

          this.propertiesKey = propertiesKey;
      }

  }

