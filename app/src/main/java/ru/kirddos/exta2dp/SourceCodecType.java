package ru.kirddos.exta2dp;

import android.bluetooth.BluetoothCodecConfig;
import android.os.Build;
import android.util.Log;

import androidx.annotation.NonNull;
import androidx.annotation.RequiresApi;

import java.lang.reflect.Field;
import java.lang.reflect.Modifier;
import java.util.Formatter;
import java.util.TreeSet;

public class SourceCodecType implements Comparable<SourceCodecType> {
    private int id;
    private String codecName;

    public SourceCodecType(int id, String codecName) {
        this.id = id;
        this.codecName = codecName;
    }

    public int getId() {
        return id;
    }
    public String getCodecName() {
        return codecName;
    }

    @Override
    public String toString() {
        return "SourceCodecType{" +
                "id=" + id +
                ", codecName='" + codecName.replace("SOURCE_CODEC_TYPE_", "") + '\'' +
                '}';
    }

    @Override
    public int compareTo(SourceCodecType o) {
        return this.id - o.id;
    }


    @RequiresApi(api = Build.VERSION_CODES.TIRAMISU)
    public static SourceCodecType[] getSourceCodecTypes() {
        TreeSet<SourceCodecType> types = new TreeSet<>();
        Field[] fields = BluetoothCodecConfig.class.getDeclaredFields();

        for (Field f: fields) {
            if (f.getType().isAssignableFrom(int.class) && isPublicStaticFinal(f.getModifiers())
                    && isSourceCodecTypeField(f.getName())) {
                f.setAccessible(true);
                try {
                    types.add(new SourceCodecType(f.getInt(null), f.getName()));
                } catch (IllegalAccessException e) {
                    throw new RuntimeException(e);
                }
            }
        }
        return types.toArray(new SourceCodecType[0]);
    }

    public static int getIdByName(String name) {
        SourceCodecType[] codecTypes = getSourceCodecTypes();

        for (SourceCodecType codec: codecTypes) {
            if (codec.codecName.equals(name)) return codec.id;
        }
        return 0;
    }


    private static boolean isPublicStaticFinal(int mod) {
        int mask = Modifier.PUBLIC | Modifier.STATIC | Modifier.FINAL;
        return (mod & mask) == mask;
    }

    private static boolean isSourceCodecTypeField(String name) {
        //Log.d("ExtA2DP", "isSourceCodecTypeField: " + name);
        return name.startsWith("SOURCE_CODEC_TYPE_");
    }
}
